/* 注意：题目保证数组不为空，且 n 大于等于 1 ，以下问题默认相同 */
int BinarySearch(int array[], int n, int value)
{
    int left = 0;
    int right = n - 1;
    // 如果这里是 int right = n 的话，那么下面有两处地方需要修改，以保证一一对应：
    // 1、下面循环的条件则是 while(left < right)
    // 2、循环内当 array[middle] > value 的时候，right = middle

    while (left <= right)  // 循环条件，适时而变
    {
        int middle = left + ((right - left) >> 1);  // 防止溢出，移位也更高效。同时，每次循环都需要更新。
        if (array[middle] > value)
            right = middle - 1;
        else if (array[middle] < value)
            left = middle + 1;
        else
            return middle;
        // 可能会有读者认为刚开始时就要判断相等，但毕竟数组中不相等的情况更多
        // 如果每次循环都判断一下是否相等，将耗费时间
    }
  
    return -1;
}