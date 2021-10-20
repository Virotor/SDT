<h1 align='center'>ТРПО. Функции. Работа с функциями</h1>

<h2 align='center'>Теоретическая часть</h2>

<h2 align='center'>Функции</h2>

### Определение и общий вид функций

***Общий вид функций***

***Type name(args){
    //тело функции
}***

***Type*** - тип возвращаемого значения функции
***name*** - имя функции
***args*** - аргументы функции

***Type name(args);*** - объявление функции

***Type name(args){}***  - определение функции

У функции может быть только одно определение.
Объявление функции должно быть до первого её вызова.

`void print(args);` - объявление функции

`int main(){`
    `print(args)`   - первый вызов функции
    `return 0;`
`}`

`void print(args){cout<<args;}` - определение функции

### Именование функций 

Название функции отражает ***суть того, что функция делает***. Функция сложения двух чисел - sum, функция вывода на экран printArray и т.д.

Если название функции состоит из нескольких слов, применяется нотация **camelCase**, т.е. ***слова пишутся слитно и первое слово пишется с маленькой буквы, а все остальные с большой буквы***. Например, функия нахождения среднего значения массива (the average of the array) - averageOfArray, максимальное значение массива - maxValueOfArray и т.д. 

***[Переводчик](https://www.google.com/search?q=%D0%BF%D0%B5%D1%80%D0%B5%D0%B2%D0%BE%D0%B4%D1%87%D0%B8%D0%BA&sxsrf=AOaemvK7FB0TWjlP173UllWQOM5iO_xaFw%3A1634667561885&ei=KQxvYd2KNen_7_UP88G74AM&ved=0ahUKEwidw-eai9fzAhXp_7sIHfPgDjwQ4dUDCA4&uact=5&oq=%D0%BF%D0%B5%D1%80%D0%B5%D0%B2%D0%BE%D0%B4%D1%87%D0%B8%D0%BA&gs_lcp=Cgdnd3Mtd2l6EAMyBwgjELADECcyBwgAEEcQsAMyBwgAEEcQsAMyBwgAEEcQsAMyBwgAEEcQsAMyBwgAEEcQsAMyBwgAEEcQsAMyBwgAEEcQsAMyBwgAEEcQsAMyBwgAELADEENKBAhBGABQAFgAYMzALmgBcAJ4AIABAIgBAJIBAJgBAMgBCrgBAcABAQ&sclient=gws-wiz)***


### Тип возвращаемого значения 

Если результат выполнения функции не имеет значения(функция вывода на экран, запись в файл), если функция выполняет действия над аргументами функции без создания нового объекта или переменной (сортировка массива, удаление элемента из массива) или если функция должна возвращать результат выполнения в качестве аргумента функции (ввод с клавиатуры, чтение из файла), то возвращаемый тип void. 

Если нам необходимо дополнительно убедиться, что функция выполнилась правильно, возвращается bool и в имя функции добавляется слово try.

Пример 1, функция вывода строки на экран

`void printMessage (string message){`
   `cout<<message<<endl;`
`}`


Пример 2, функция ввода числа с клавиатуры 

`bool tryEnterNumber(int* enteredNumber){`  
   ` // Код ввода числа и его проверки`
   `return true;`
`}`

Пример 3, функция сортировки массива

`void sortArray (Type* array, size_t sizeOfArray){`
    `//Алгоритм сортировки`
`}`

> Type тип массива

Если функция возвращает просто значение перменной, то тип возвращаемого значения равен типу переменной. Например, кол-во элементов в массиве - это целое число, возвращаемый тип int, сумма элементов массива - зависит от типа массива, может быть целым числом (int, long) или числом с плавающей запятой (float, double), элемент массива - тип массива.

Пример 1, функция возврата кол-ва символов в строке, которые равны заданному символу

`int coutOfOccurrencesOfCharacter(string str, char symbol){`
    `int count = 0 // кол-во символов строки, равных заданому`
    `//Алгоритм поиска символа в строке`
    `return count;`
`}`

Пример 2, функция нахождения среднего значения массива целых чисел 

`double averageOfArray (int* array, size_t sizeOfArray){`
    `int sum =0;`
    `//Алгоритм нахожения суммы элементов массива`
    `double average =((double) sum) / sizeOfArray;`
    `return average;`  
`}`

### Аргументы функций 

В качестве аргументов функции могут выступать переменные (int a, double b, string str), указатели (int* a, double** b, string* str) и ссылки(int &a, double &b, string &str), другие функции(double func(double)). 

Перменные используются, если нам необходима ***копия переменной***. Значения переменной внутри функции могут изменятся, но сами переменные, которые были переданы в функцию ***в месте вызова не будут изменены***. 

Пример 1

`void printSumAndAvarageOfArray(int sumOfArray, size_t sizeOfArray){`
    `cout<<"Sum and average of array = " << sumOfArray<< " " << ((double)sumOfArray)/sizeOfArray <<endl;`
    `sumOfArray--;`
`}`


`//`
`int sumOfArray = 10;`
`size_t sizeOfArray = 10;`
`printSumAndAvarageOfArray(sumOfArray, sizeOfArray);`
`// Значение переменной sumOfArray не изменится`

Если нам необходимо, чтобы значение ***не просто копировалось в функцию***, а чтобы оно ***изменялось*** в функции и это изменение ***вернулось***, используются ***ссылки и указатели***. 

Пример 2, код из примера 1


`void printSumAndAvarageOfArray(int* sumOfArray, size_t sizeOfArray){`
    `cout<<"Sum and average of array = " << *sumOfArray<< " " << ((double)*sumOfArray)/sizeOfArray <<endl;`
    `(*sumOfArray)--;`
`}`


`//`
`int sumOfArray = 10;`
`size_t sizeOfArray = 10;`
`printSumAndAvarageOfArray(&sumOfArray, sizeOfArray); //& - означает, что мы берём не просто значение переменной, а её адрес` 
`// Значение переменной sumOfArray будет равно 9`

Для сортировок обычно используются функции, которые могут принимать в себя другие функции, чтобы сортировать данные определённым способом.

`bool sortAscending(int left, int right){`
    `if(left > right){`
        `return true;`
    `}`
    `return false;`
`}`

`bool sortDescending(int left, int right){`
    `if(left < right){`
        `return true;`
    `}`
    `return false;`
`}`

`void sortArray(int* array, size_t sizeOfArray, bool predicate(int, int)){`
    `for(int i = 1; i < sizeOfArray; ++i){`
	    `for(int j = 0; j< sizeOfArray-i; j++){`
		    `if(predicate(array[j],array[j+1]))`
		    `{`
			`int temp = array[j];`
			`array[j] = array[j+1];`
			`array[j+1] = temp;`
		    `}`
	    `}`
    `}`   
`}`

`sortArray(array, sizeOfArray, sortAscending)`
`sortArray(array, sizeOfArray, sortDescending)`

### Перегрузка функций 

В современных языках программирования есть перегрузка функций, т.е. в зависимости от переданных аргументов, вызывается определённое определение функции

Пример, перегрузка функции вывода на экран

`void print(int** matrix, size_t row, size_t column){`
    `for(int i =0;i<row; i++){`
        `for(int j=0; j< column;j++){`
            `cout<<matrix[i][j]<<" ";`
        `}`
        `cout<<endl;`
    `}`
`}`

`void print(int* array, size_t sizeOfArray){`
    `for(int i =0;i<row; i++){`
        `cout<<array[i][j]<<" ";`
    `}`
`}`

`print(matrix,row,column)`
`print(array, sizeOfArray)`

В первом случае выведется матрица, во втором будет выведен массив.

Перегружать можно любые функции, но при перегрузке учитываются только аргументы функции, если поменять тип возвращаемого значения, перегрузки не будет. 

<h2 align='center'>Задание</h2>

1. Написать ***свою функцию*** перевода строки в число. На входе целое число, а на выходе строка.
2. Перегрузить функцию из задания 1 несколько раз. Например, перевод числа с плавающей запятой в строку, перевод не всего числа, а только заданное кол-во элементов.
3. Написать функцию, которая находит кол-во встреч в массиве заданного числа. Т.е. {1,2,3,4,5,5,5,6,7} - 5 встречается 3 раза. Перегрузить, чтобы работало для строковых типов (char или string).

