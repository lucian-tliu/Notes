import numpy as np
from skimage.measure import marching_cubes
from vispy import scene, app
from vispy.visuals import transforms
from matplotlib import cm
app.use_app('pyqt5')

def plot_orbital_3d_vispy(probability_density, n, l, m,
                          threshold=0.01,
                          colormap='viridis',
                          bgcolor=(0, 0, 0, 1),
                          window_size=(1000, 800)):
    """
    用 VisPy 渲染 marching_cubes 提取的 3D 网格。
    参数:
      - probability_density: 3D ndarray (cartesian grid)（你传入的应已为笛卡尔体数据）
      - n, l, m: 仅用于标题显示
      - threshold: 等值面相对于最大值的比例（例如 0.01）
      - colormap: matplotlib colormap 名称，用于着色
      - bgcolor: 背景颜色 RGBA
      - window_size: vispy 窗口尺寸
    """
    # 提取等值面
    try:
        verts, faces, normals, values = marching_cubes(
            probability_density, level=threshold * np.max(probability_density))
    except ValueError as exc:
        # 常见错误：No surface found at the given iso value.
        print("Error from marching_cubes:", exc)
        print("建议：降低 threshold（例如 0.001）或检查 probability_density 的范围。")
        return

    # -----------------------
    # 颜色：按每个顶点的插值值着色
    # -----------------------
    # 归一化顶点值到 [0,1]
    # vmin, vmax = values.min(), values.max()
    # if vmax - vmin < 1e-12:
    #     norm_vals = np.zeros_like(values)
    # else:
    #     norm_vals = (values - vmin) / (vmax - vmin)
    z = verts[:, 2]
    z_min, z_max = z.min(), z.max()
    if z_max - z_min < 1e-12:
        t = np.zeros_like(z)
    else:
        t = (z - z_min) / (z_max - z_min)

    # 使用 matplotlib colormap 得到 RGBA 顶点颜色
    cmap = cm.get_cmap(colormap)
    vertex_colors = np.column_stack([1 - t, np.zeros_like(t), t, np.ones_like(t)]).astype(np.float32)

    # 将顶点颜色映射到 faces 的面颜色（可选）
    face_colors = vertex_colors[faces].mean(axis=1)

    # -----------------------
    # VisPy 渲染
    # -----------------------
    canvas = scene.SceneCanvas(keys='interactive', title=f'3D Orbital: n={n}, l={l}, m={m}',
                               size=window_size, show=True, bgcolor=bgcolor)

    view = canvas.central_widget.add_view()

    # Mesh: 使用顶点颜色或面颜色
    mesh = scene.visuals.Mesh(vertices=verts.astype(np.float32),
                              faces=faces.astype(np.uint32),
                              vertex_colors=vertex_colors.astype(np.float32),
                              shading='smooth',  # 'smooth' or 'flat'
                              parent=view.scene)

    # 把网格平移到原点附近（便于相机围绕旋转）
    center = verts.mean(axis=0)
    # mesh.transform = transforms.STTransform(translate=-center)

    # 相机：可交互的 turntable（鼠标左键旋转，滚轮缩放）
    cam = scene.cameras.TurntableCamera(fov=45, azimuth=30, elevation=30, parent=view.scene)
    # 设置合理的距离，使目标完全入镜
    extent = np.linalg.norm(verts.max(axis=0) - verts.min(axis=0))
    cam.distance = extent * 1.5
    view.camera = cam

    # 添加坐标轴小组件（右上角）
    # axis = scene.visuals.XYZAxis(parent=view.scene)
    # axis.transform = transforms.STTransform(translate=(0.1 * extent, 0.1 * extent, 0.1 * extent),
    #                                        scale=(extent * 0.05, extent * 0.05, extent * 0.05))

    # 可选：在右上角显示色条（用 2D overlay 的办法）
    # 这里简单示范：用一个小矩形条显示渐变（非精确色条）
    # （如需精确色条，可用 vispy.plot 或 matplotlib 做单独窗口）
    # 你可以启用/扩展此部分

    # 运行 vispy app（阻塞，直到窗口关闭）
    app.run()

if __name__ == "__main__":
    # 举例：载入 .npy 或者你自己的 psi_density
    probability_density = np.load("psi_density.npy")   # ← 替换

    plot_orbital_3d_vispy(probability_density, n=1, l=0, m=0, threshold=0.01)