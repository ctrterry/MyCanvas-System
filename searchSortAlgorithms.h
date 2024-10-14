template <class elemType>
int seqSearch(const elemType list[], int length, const elemType& item)
{
    int loc;
    bool found = false;
    loc = 0;

    while (loc < length && !found)
        if (list[loc] == item)
            found = true;
        else
            loc++;

    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <class elemType>
int binarySearch(const elemType list[], int length, const elemType& item)
{
    int first = 0;
    int last = length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (list[mid] == item)
            found = true;
        else if (list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found)
        return mid;
    else
        return -1;
} //end binarySearch


template <class elemType>
int recursiveBinarySearch(const elemType list[], int length, const elemType& item)
{
    return recBinarySearch(list, item, 0, length - 1);
} //end recursiveBinarySearch

template <class elemType>
int recBinarySearch(const elemType list[], const elemType& item, int first, int last)
{
    int mid;

    if (first <= last)
    {
        mid = (first + last) / 2;

        if (list[mid] == item)
            return mid;
        else if (list[mid] > item)
            return recBinarySearch(list, item, first, mid - 1);
        else
            return recBinarySearch(list, item, mid + 1, last);
    }
    else
        return -1;
} //end recBinarySearch

template <class elemType>
void swap(elemType list[], int first, int second)
{
    elemType temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
} //end swap

template <class elemType>
void bubbleSort(elemType list[], int length)
{
    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration; index++)
        {
            if (list[index] > list[index + 1]) {
                swap(list, index, index + 1);
            }
        }
    }
} //end bubbleSort

template <class elemType>
int minLocation(elemType list[], int first, int last, bool ascending)
{
    int loc, minIndex;

    minIndex = first;

    for (loc = first + 1; loc <= last; loc++) {
        if ((list[loc] < list[minIndex]) == ascending) {
            minIndex = loc;
        }
    }

    return minIndex;
} //end minLocation

template <class elemType>
void selectionSort(elemType list[], int length, bool ascending = true)
{
    int loc, minIndex;

    for (loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1, ascending);
        swap(list, loc, minIndex);
    }
} //end selectionSort

template <class elemType>
int partition(elemType list[], int first, int last)
{
    elemType pivot;

    int index, smallIndex;

    swap(list, first, (first + last) / 2);

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++) {
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(list, smallIndex, index);
        }
    }

    swap(list, first, smallIndex);

    return smallIndex;
} //end partition

template <class elemType>
void quickSort(elemType list[], int length)
{
    recQuickSort(list, 0, length - 1);
} //end quickSort

template <class elemType>
void recQuickSort(elemType list[], int first, int last)
{
    int pivotLocation;

    if (first < last) {
        pivotLocation = partition(list, first, last);
        recQuickSort(list, first, pivotLocation - 1);
        recQuickSort(list, pivotLocation + 1, last);
    }
} //end recQuickSort