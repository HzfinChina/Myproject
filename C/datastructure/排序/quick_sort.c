void quick_sort(int *array, int left, int right){
    if (left >= right)
        return;
    int pivot = array[left];
    int i = left, j = right; 
    while (i < j){
        // fuck! the '=' wasted me lots time to debug
        // don't miss it or it will be trapped in dead cycle
        while(array[j] >= pivot && i < j){
            j--;
        }
        if (i < j)
            array[i++] = array[j];
        while(array[i] < pivot && i < j){
            i++;
        }
        if (i < j)
            array[j--] = array[i];
        
    }
    array[i] = pivot;
    quick_sort(array, left, i);
    quick_sort(array, i+1, right);
}
