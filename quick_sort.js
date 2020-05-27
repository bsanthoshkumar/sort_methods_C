const swapArray = (array, i, j) => {
  temp = array[i];
  array[i] = array[j];
  array[j] = temp;
};

const quickSort = (array, startIndex, pivotIndex) => {
  if (startIndex < pivotIndex) {
    let i = startIndex;
    for (let j = startIndex; j < pivotIndex; j++) {
      if (array[j] < array[pivotIndex]) {
        swapArray(array, i, j);
        i++;
      }
    }
    swapArray(array, i, pivotIndex);
    quickSort(array, startIndex, i - 1);
    quickSort(array, i + 1, pivotIndex);
  }
};

const main = () => {
  let array = [13, 2, 8, 28, 12, 9, 3, 18, 1, 4];
  quickSort(array, 0, 9);
  console.log(array);
};

main();
