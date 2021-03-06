# Теоретическая часть 
## Цикл while(condition)

Цикл while выполняет некоторый код, пока его условие истинно, то есть возвращает true. Он имеет следующее формальное определение:  

`while(condition){`  
   `//Выполняемый код`  
`}`  

После ключевого слова while в скобках идет условное выражение, которое возвращает true или false. Затем в фигурных скобках идет набор инструкций, которые составляют тело цикла. И пока условие возвращает 
true, будут выполняться инструкции в теле цикла.  

Пример, сумма первых n чисел:  
`int i = 0;`  
`int sum = 0;`  
`while (i<=n){`  
   `   sum+=i;`  
   `   i++;`  
`}`

## Цикл for  

`for(выражение_1;выражение_2;выражение_3){`  
`//выполняемый код`  
`}`  

выражение_1 выполняется один раз при начале выполнения цикла и представляет установку начальных условий, как правило, это инициализация счетчиков - специальных переменных, которые используются для контроля за циклом.

выражение_2 представляет условие, при соблюдении которого выполняется цикл. Как правило, в качестве условия используется операция сравнения, и если она возвращает ненулевое значение (то есть условие истинно), то выполняется тело цикла, а затем вычисляется выражение_3.

выражение_3 задает изменение параметров цикла, нередко здесь происходит увеличение счетчиков цикла на единицу.

Пример, сумма первых n чисел:   
`int sum = 0;`  
`for(int i = 0; i<=n;i++){`  
   `   sum+=i;`  
`}`
> Необязательно указывать все три выражения в определении цикла, мы можем одно или даже все из них опустить.

## Цикл do 
В цикле do сначала выполняется код цикла, а потом происходит проверка условия в инструкции while. И пока это условие истинно, то есть не равно 0, то цикл повторяется. Формальное определение цикла:

`do`  
`{`  
 `//выполняемый код`  
 `}while(condition)`  
 
> Цикл do гарантирует хотя бы однократное выполнение действий, даже если условие в инструкции while не будет истинно

## Операторы continue, break

Иногда возникает необходимость выйти из цикла до его завершения. В этом случае можно воспользоваться оператором break.

В отличие от оператора break, оператор continue производит переход к следующей итерации. 

# Задание на ПЗ

1. Посчитать площадь и периметр прямоугольника. Нарисовать получившийся прямоугольник.
2. Ввести число n (n>0). Вывести первые n чисел Фибоначчи. Посчитать факториал числа n.    
   > Числа Фибоначчи.Числовая последовательность, где первые два числа 0 1, а каждое последующее число равно сумме двух предыдущих чисел. 
3. Ввести два числа, определить являются ли они простыми. Найти наибольший общий делитель.  
4. Вывести на экран двоичное представление числа.
5. Написать функцию, которая будет генерировать случайные числа. Сгенерировать числа и постороить график распределения.  

Задания выполнять без использования рекурсии.
