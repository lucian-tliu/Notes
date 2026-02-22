# NumPy 科学计算库详解

NumPy (Numerical Python) 是 Python 科学计算的核心库，提供了高性能的多维数组对象 `ndarray` 以及处理这些数组的工具。

---

## 1. NumPy Array 对象 (ndarray)

`ndarray` 是一个多维、同质（所有元素类型相同）的数组容器。

### 1.1 核心属性

| 属性 | 说明 | 示例 |
| :--- | :--- | :--- |
| `ndarray.ndim` | 数组的维度数量（秩） | 2 (表示二维数组) |
| `ndarray.shape` | 数组的形状，返回一个元组 | `(3, 4)` (3行4列) |
| `ndarray.size` | 数组元素的总个数 | 12 |
| `ndarray.dtype` | 数组元素的类型对象 | `dtype('int64')` |
| `ndarray.itemsize` | 每个元素的大小（字节） | 8 |
| `ndarray.data` | 指向数据内存的缓冲区 | (通常不直接使用) |

### 1.2 数据类型 (dtype)

NumPy 支持比 Python 原生更多样的数据类型。

| 类型 | 描述 |简写代码|
| :--- | :--- | :--- |
| `int8`, `int16`, `int32`, `int64` | 有符号整数 | `i1`, `i2`, `i4`, `i8` |
| `uint8`, `uint16`, ... | 无符号整数 | `u1`, `u2`, ... |
| `float16`, `float32`, `float64` | 浮点数 | `f2`, `f4`, `f8` |
| `complex64`, `complex128` | 复数 | `c8`, `c16` |
| `bool` | 布尔类型 | `b1` |
| `object` | Python对象 | `O` |
| `string_` | 固定长度字符串 | `S` |
| `unicode_` | 固定长度Unicode | `U` |

**类型转换与指定：**

```python
import numpy as np

# 创建时指定类型
arr = np.array([1, 2, 3], dtype=np.float32)

# 转换类型 (astype 返回一个新数组，即副本)
float_arr = arr.astype(np.int64)

# 解析字符串类型
numeric_strings = np.array(['1.25', '-9.6'], dtype=np.string_)
data = numeric_strings.astype(float)
```

---

## 2. 创建数组

### 2.1 从现有数据创建

| 函数 | 说明 |
| :--- | :--- |
| `np.array(object)` | 将列表、元组等转换为数组 |
| `np.asarray(a)` | 将输入转换为数组，如果输入本身是数组则不复制 |
| `np.copy(a)` | 返回数组的深拷贝 |

### 2.2 生成固定范围的数组

| 函数 | 说明 | 示例 |
| :--- | :--- | :--- |
| `np.arange(start, stop, step)` | 类似 Python range，返回数组 | `np.arange(0, 10, 2)` |
| `np.linspace(start, stop, num)` | 在区间内生成均匀分布的 `num` 个点 | `np.linspace(0, 1, 5)` |
| `np.logspace(start, stop, num)` | 在对数尺度上生成均匀分布的点 | `np.logspace(0, 2, 5)` |

### 2.3 生成特定填充的数组

| 函数 | 说明 |
| :--- | :--- |
| `np.zeros(shape)` | 全 0 数组 |
| `np.ones(shape)` | 全 1 数组 |
| `np.empty(shape)` | 创建未初始化的数组（内容随机，速度快） |
| `np.full(shape, fill_value)` | 填充指定数值的数组 |
| `np.eye(N)` / `np.identity(N)` | N x N 的单位矩阵 |

### 2.4 生成随机数组 (`np.random`)

| 函数 | 说明 |
| :--- | :--- |
| `np.random.rand(d0, d1, ...)` | [0, 1) 均匀分布 |
| `np.random.randn(d0, d1, ...)` | 标准正态分布 (均值0, 方差1) |
| `np.random.randint(low, high, size)` | 随机整数 [low, high) |
| `np.random.choice(a, size, replace, p)` | 从 a 中随机抽取样本 |
| `np.random.shuffle(x)` | 现场打乱数组顺序 |
| `np.random.seed(s)` | 设置随机种子 |

---

## 3. 索引与切片 (Indexing & Slicing)

### 3.1 基础索引与切片

与 Python 列表类似，但支持多维操作。

```python
arr = np.arange(10)
print(arr[5])    # 索引
print(arr[5:8])  # 切片：[5, 6, 7]
arr[5:8] = 12    # 广播赋值：将 12 赋值给 5-7 位置

# 多维数组
arr2d = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
print(arr2d[0, 2])  # 第0行第2列 -> 3
print(arr2d[:2, 1:]) # 前两行，从第1列开始的所有列
```

**重要：** 数组切片是**视图 (View)**，不是副本。修改切片会改变原数组。如果需要副本，请显式使用 `.copy()`。

### 3.2 布尔索引 (Boolean Indexing)

使用布尔条件选择元素，**返回的是副本**。

```python
names = np.array(['Bob', 'Joe', 'Will', 'Bob'])
data = np.random.randn(4, 4)

# 选出 names == 'Bob' 对应的行
print(data[names == 'Bob'])

# 组合条件 & (and), | (or)
mask = (names == 'Bob') | (names == 'Will')
print(data[mask])

# 将所有负值设为 0
data[data < 0] = 0
```

### 3.3 花式索引 (Fancy Indexing)

使用整数数组进行索引，**返回的是副本**。

```python
arr = np.zeros((8, 4))
for i in range(8):
    arr[i] = i

# 选取特定的行，顺序亦可指定
print(arr[[4, 3, 0, 6]])

# 选取特定的行列坐标元素
arr = np.arange(32).reshape((8, 4))
print(arr[[1, 5, 7, 2], [0, 3, 1, 2]]) # 选出 (1,0), (5,3), (7,1), (2,2)
```

---

## 4. 数组操作与变形

### 4.1 改变形状

| 函数 | 说明 | 注意 |
| :--- | :--- | :--- |
| `arr.reshape(shape)` | 返回新形状的数组 | 尽量返回视图，不复制数据 |
| `arr.resize(shape)` | **原地**修改数组形状 | 无返回值 |
| `arr.ravel()` | 展平为一维数组 | 返回视图 |
| `arr.flatten()` | 展平为一维数组 | **返回副本** |
| `np.expand_dims(arr, axis)` | 增加维度 | 例如 (3,) -> (3, 1) |
| `np.squeeze(arr)` | 删除维度为1的轴 | 例如 (3, 1) -> (3,) |

### 4.2 数组合并与拆分

*   **合并**: `np.concatenate`, `np.vstack` (垂直), `np.hstack` (水平)
*   **拆分**: `np.split`, `np.vsplit`, `np.hsplit`

```python
arr1 = np.array([[1, 2, 3]])
arr2 = np.array([[4, 5, 6]])

# 垂直堆叠
np.vstack((arr1, arr2)) 
# 结果: [[1, 2, 3], [4, 5, 6]]

# 水平堆叠
np.hstack((arr1, arr2))
# 结果: [[1, 2, 3, 4, 5, 6]]
```

### 4.3 转置与轴交换

*   `arr.T`: 转置（适用于1维和2维）
*   `arr.transpose(*axes)`: 通用的轴交换
*   `arr.swapaxes(ax1, ax2)`: 交换两个轴

---

## 5. 向量化计算与广播 (Broadcasting)

**向量化**：避免使用 Python for 循环，直接对数组进行批量运算，利用底层 C 语言优化。

**广播机制**：NumPy 允许不同形状的数组进行算术运算。
**规则**：如果两个数组的后缘维度（trailing dimensions，即从末尾开始算起的维度）的轴长度相符或其中一方的长度为1，则认为它们是广播兼容的。

```python
# 示例：矩阵减去列平均值
arr = np.random.randn(4, 3)
means = arr.mean(axis=0) # shape (3,)
demeaned = arr - means   # 广播操作：(4,3) - (3,) -> (3,) 广播为 (4,3)
```

---

## 6. 数学与统计函数

### 6.1 元素级函数 (Universal Functions, ufunc)

| 函数 | 说明 |
| :--- | :--- |
| `np.abs`, `np.fabs` | 绝对值 |
| `np.sqrt`, `np.square` | 平方根，平方 |
| `np.exp` | 指数 $e^x$ |
| `np.log`, `np.log10`, `np.log2` | 对数 |
| `np.sign` | 符号函数 (1, 0, -1) |
| `np.ceil`, `np.floor` | 向上/向下取整 |
| `np.isnan` | 判断是否为 NaN |
| `np.maximum`, `np.minimum` | 元素级最大/最小值 |

### 6.2 聚合函数 (统计方法)

通常可以指定 `axis` 参数。`axis=0` 代表沿行（纵向）计算，`axis=1` 代表沿列（横向）计算。

| 函数 | 说明 |
| :--- | :--- |
| `np.sum` | 求和 |
| `np.mean` | 平均值 |
| `np.std`, `np.var` | 标准差，方差 |
| `np.min`, `np.max` | 最小值，最大值 |
| `np.argmin`, `np.argmax` | 最小/最大元素的索引 |
| `np.cumsum` | 累积和 |
| `np.cumprod` | 累积积 |
| `np.any`, `np.all` | 逻辑判断：是否存在/是否全部为True |

### 6.3 集合逻辑

| 函数 | 说明 |
| :--- | :--- |
| `np.unique(x)` | 找出唯一值并排序 |
| `np.intersect1d(x, y)` | 计算 x 和 y 的交集 |
| `np.union1d(x, y)` | 计算 x 和 y 的并集 |
| `np.in1d(x, y)` | 检查 x 的元素是否包含在 y 中，返回布尔数组 |
| `np.setdiff1d(x, y)` | 计算 x 和 y 的差集 (在 x 中但不在 y 中的元素) |
| `np.setxor1d(x, y)` | 计算 x 和 y 的对称差集 (不属于交集的元素) |

---

## 7. 线性代数 (Linear Algebra)

`numpy.linalg` 模块提供了标准的线性代数运算。

### 7.1 常用矩阵运算

| 函数 | 描述 | 示例 |
| :--- | :--- | :--- |
| `np.dot` | 矩阵乘法 / 点积 | `np.dot(a, b)` 或 `a.dot(b)` |
| `@` 运算符 | 矩阵乘法 (Python 3.5+) | `a @ b` |
| `np.trace` | 计算对角线元素的和（迹） | `np.trace(a)` |
| `np.linalg.det` | 计算矩阵行列式 | `np.linalg.det(a)` |
| `np.linalg.eig` | 计算特征值和特征向量 | `w, v = np.linalg.eig(a)` |
| `np.linalg.inv` | 计算逆矩阵 | `np.linalg.inv(a)` |
| `np.linalg.pinv` | 计算 Moore-Penrose 伪逆 | `np.linalg.pinv(a)` |
| `np.linalg.qr` | QR 分解 | `q, r = np.linalg.qr(a)` |
| `np.linalg.svd` | 奇异值分解 (SVD) | `u, s, vh = np.linalg.svd(a)` |
| `np.linalg.solve` | 求解线性方程组 $Ax = b$ | `x = np.linalg.solve(A, b)` |

### 7.2 高级向量与矩阵积

以下是处理多维数组积和特定向量操作的函数：

| 函数 | 描述 | 示例/说明 |
| :--- | :--- | :--- |
| `np.inner` | **向量内积**。对于一维数组，等同于 `np.dot`。对于高维，计算最后维度的乘积和。 | `np.inner(a, b)` |
| `np.outer` | **向量外积**。给定两个向量 $u, v$，计算 $u v^T$。 | `np.outer(a, b)` |
| `np.cross` | **向量叉乘**。计算两个向量的叉积（仅适用于 2D 或 3D 向量）。 | `np.cross(a, b)` |
| `np.tensordot` | **张量点积**。沿指定轴计算张量收缩。 | `np.tensordot(a, b, axes=1)` |
| `np.kron` | **Kronecker 积**。计算两个数组的 Kronecker 积（直积）。结果形状是输入形状的乘积。 | `np.kron(a, b)` |
| `np.einsum` | **Einstein 求和约定**。强大的多维数组运算工具，可表示点积、外积、转置等。 | `np.einsum('ij,jk->ik', A, B)` (矩阵乘法) |

---

## 8. 文件输入输出 (I/O)

| 函数 | 说明 |
| :--- | :--- |
| `np.save(file, arr)` | 以二进制 `.npy` 格式保存单个数组 |
| `np.load(file)` | 加载 `.npy` 或 `.npz` 文件 |
| `np.savez(file, a=arr1, b=arr2)` | 以未压缩的 `.npz` 格式保存多个数组 |
| `np.savez_compressed` | 以压缩格式保存多个数组 |
| `np.savetxt(file, arr, delimiter=',')` | 保存为文本文件 (如 CSV) |
| `np.loadtxt(file, delimiter=',')` | 加载文本文件 |
