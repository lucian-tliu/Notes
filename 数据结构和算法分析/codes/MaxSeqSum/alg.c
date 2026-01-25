int MaxSeqSum1(int A[], int N)
{
    int ThisSum, MaxSum, i, j, k;

    MaxSum = 0;
    for (i = 0; i < N; i++)
        for (j = i; j < N; j++)
        {
            ThisSum = 0;
            for (k = i; k <= j; k++)// 这里浪费了时间，不需要重新从i开始
                ThisSum += A[k];

            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    return MaxSum;
}

int MaxSeqSum2(int A[], int N)
{
    int ThisSum, MaxSum, i, j;
    
    MaxSum = 0;
    for (i = 0; i < N; i++){
        ThisSum = 0; 
        for (j = i; j < N; j++){
            ThisSum += A[j];
           	if (ThisSum > MaxSum){
            	MaxSum = ThisSum;
        	}
        }
    }
    
    return MaxSum;
}

int MaxSeqSum3(int A[], int Left, int Right)
{
    int MaxLeft, MaxRight;
    int MaxCrossLeft, MaxCrossRight;
    int LeftCrossSum, RightCrossSum;
    int MaxCross;

    if (Left == Right)
        if (A[Left] > 0)
            return A[Left];
        else
            return 0;

    int Center = (Left + Right) / 2;
    MaxLeft = MaxSeqSum3(A, Left, Center);
    MaxRight = MaxSeqSum3(A, Center+1, Right);

    // 处理左侧部分
    LeftCrossSum = 0;
    MaxCrossLeft = 0;
    for (int i=Center; i >= Left; i--){
        LeftCrossSum += A[i];
        if (LeftCrossSum > MaxCrossLeft)
            MaxCrossLeft = LeftCrossSum;
    }

    // 处理右侧部分
    RightCrossSum = 0;
    MaxCrossRight = 0;
    for (int i=Center+1; i <= Right; i++){
        RightCrossSum += A[i];
        if (RightCrossSum > MaxCrossRight)
            MaxCrossRight = RightCrossSum;
    }

    MaxCross = MaxCrossLeft + MaxCrossRight;

    // 返回三者中的最大值
    return (MaxLeft > MaxRight) ? 
           ((MaxLeft > MaxCross) ? MaxLeft : MaxCross) :
           ((MaxRight > MaxCross) ? MaxRight : MaxCross);
}

int MaxSeqSum4(int A[], int N)
{
    int ThisSum = 0;
    int MaxSum = 0;
    for (int i = 0; i < N; i++){
        ThisSum += A[i];
        if (ThisSum > MaxSum){
            MaxSum = ThisSum;
        } else if (ThisSum < 0){
            ThisSum = 0;
        }
    }
    return MaxSum;
}
