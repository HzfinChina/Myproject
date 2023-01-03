void selection_sort(int *array, int size){
    int i, j, temp, minindex;
    for (i = 0; i < size; i++){
        minindex = i;
        for (j = i; j < size; j++){
            minindex = array[minindex] < array[j] ? minindex : j;
        }
        temp = array[i];
        array[i] = array[minindex];
        array[minindex] = temp;
    }
}
