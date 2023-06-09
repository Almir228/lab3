**Структура**

Данная структура ListPair_t представляет собой узел (ноду) связного списка, который содержит целочисленное значение data и указатель на следующий узел next.



**add_node**

Данная функция add_node создает новый узел со значением data и вставляет его в начало связного списка, на место головного узла.

Конструкция new ListPair_t {data, head} создает новый объект типа ListPair_t, инициализируя его значениями data и head. Затем эта новая нода становится новой головой списка, поскольку ее указатель next указывает на предыдущую голову списка, которая передается в качестве аргумента head.

Возвращаемое значение функции - указатель на новый узел, который теперь является головой списка. Если вы захотите использовать этот код, не забудьте удалить узлы в связном списке после их использования, чтобы избежать утечек памяти.

**Get adress**

Данная функция get_adress возвращает указатель на узел связного списка по заданному индексу number.

Аргумент head является указателем на голову связного списка. Аргумент number - индекс узла, адрес которого требуется получить.

Функция начинает обход списка, начиная с головного узла, и переходит к следующему узлу через указатель next. Она продолжает обход списка до тех пор, пока не достигнет узла с заданным индексом number или не дойдет до конца списка.

Если в списке меньше узлов, чем заданный индекс number, то функция возвращает нулевой указатель nullptr.

Если узел с заданным индексом найден, то функция возвращает указатель на этот узел.

Эта функция может быть полезна, например, для удаления или изменения узла в списке по его индексу.

**get_data**

Данная функция get_data возвращает значение данных (поле data) узла связного списка по заданному индексу number.

Аргумент head является указателем на голову связного списка. Аргумент number - индекс узла, данные которого требуется получить.

Функция использует уже определенную ранее функцию get_adress, которая возвращает указатель на узел по заданному индексу. Затем функция возвращает значение поля data найденного узла.

Если в списке меньше узлов, чем заданный индекс number, то функция возвращает некорректное значение (например, значение из какой-то другой части памяти), так как пытается получить доступ к несуществующей ноде или ноде с некорректным адресом. Поэтому, перед вызовом этой функции, следует убедиться, что индекс number не превышает длину списка.


**PrintList**

Данная функция PrintList печатает значения данных (поле data) всех узлов связного списка, начиная с головного узла.

Аргумент head является указателем на голову связного списка.

Функция использует цикл while для обхода списка, начиная с головного узла, и выводит значения поля data каждого узла на экран. Затем указатель переходит к следующему узлу через указатель next, пока не дойдет до конца списка (то есть пока указатель h не будет равен нулевому указателю nullptr).

Функция может быть полезна для отладки кода, чтобы убедиться, что все узлы связного списка были созданы и их данные корректно сохранены.


**add_after**

Данная функция add_after добавляет новый узел после узла с заданным индексом number в связный список.

Аргумент head является указателем на голову связного списка. Аргумент number - индекс узла, после которого нужно добавить новый узел. Аргумент data - значение данных, которые нужно сохранить в новом узле.

Функция использует цикл for для обхода списка, начиная с головного узла, и переходит к следующему узлу через указатель next, пока не достигнет узла с заданным индексом number или не дойдет до конца списка. Если индекс number превышает длину списка, то функция выводит сообщение об ошибке и возвращает false.

Если узел с заданным индексом найден, то функция вызывает функцию add_node, которая создает новый узел и возвращает указатель на него. Затем функция добавляет новый узел в список, указывая на него указателем next узла, после которого он должен быть добавлен, и устанавливает указатель next для предыдущего узла, чтобы он указывал на новый узел.

Функция возвращает true, если добавление узла прошло успешно, и false, если произошла ошибка.


**add_after**

Данная функция add_after добавляет новый узел после указанного узла в связный список.

Аргумент ptr является указателем на узел, после которого нужно добавить новый узел. Аргумент data - значение данных, которые нужно сохранить в новом узле.

Функция вызывает функцию add_node, которая создает новый узел и возвращает указатель на него. Затем функция добавляет новый узел в список, указывая на него указателем next указанный узел, и устанавливает указатель next для указанного узла, чтобы он указывал на новый узел.

Эта функция не выполняет проверку на правильность введенных данных или индекса узла, так что необходимо убедиться, что указатель ptr указывает на существующий узел в списке и что значение data содержит корректные данные.


**bool remove_after**

Данная функция remove_after удаляет узел, следующий за указанным узлом, из связного списка.

Аргумент head является указателем на голову связного списка. Аргумент number является индексом узла, после которого нужно удалить узел.

Функция сначала проверяет, существует ли узел, следующий за указанным узлом, проверяя наличие указателя next текущего узла. Если такого узла нет, функция выводит сообщение об ошибке и возвращает false.

Затем функция сохраняет указатель на узел, следующий за удаляемым узлом, в переменную hh, затем удаляет узел, следующий за указанным узлом, с помощью оператора delete и обновляет указатель next для текущего узла, чтобы он указывал на узел, следующий за удаленным узлом, используя сохраненный указатель hh.

Функция возвращает true, если узел был успешно удален из списка, и false в противном случае.


**void remove_after**

Данная функция remove_after удаляет узел, следующий за указанным узлом, из связного списка.

Аргумент ptr является указателем на узел, после которого нужно удалить узел.

Функция сначала сохраняет указатель на узел, следующий за удаляемым узлом, в переменную h, затем обновляет указатель next для указанного узла, чтобы он указывал на узел, следующий за удаленным узлом, используя указатель next для сохраненного указателя h. Затем функция удаляет узел, следующий за указанным узлом, с помощью оператора delete.

Эта функция не выполняет проверку на правильность введенных данных или наличие указателя на узел, следующий за указанным узлом, так что необходимо убедиться, что указатель ptr указывает на существующий узел в списке и что следующий узел, на который он указывает, существует.


**erase**

Функция erase удаляет все узлы списка, начиная с головного элемента. Она использует цикл while для последовательного удаления всех узлов списка, начиная с головного элемента, пока следующий элемент не станет равным nullptr. Затем она удаляет головной элемент, используя оператор delete.

**recursion_remove**

Данная функция recursion_remove использует рекурсивный подход для удаления всех узлов связного списка, начиная с указанного узла head.

Функция сначала проверяет, существует ли узел, следующий за указанным узлом head. Если это так, функция вызывает remove_after для удаления этого узла и затем рекурсивно вызывает recursion_remove для удаления следующего узла. Если же узел, следующий за указанным узлом, не существует, это значит, что вся цепочка узлов была удалена, и функция удаляет указанный узел с помощью оператора delete и возвращает 1.

Важно отметить, что при использовании рекурсивного подхода необходимо следить за тем, чтобы не превышать максимальную глубину рекурсии, так как это может привести к переполнению стека.


**reverse_itr**
Данная функция reverse_itr использует итеративный подход для обращения порядка узлов в связном списке, начиная с указанного узла head.

Функция создает три указателя: prev, curr и nextNode. prev инициализируется как nullptr, curr инициализируется как указанный узел head, а nextNode инициализируется как nullptr.

Затем функция запускает цикл while, который будет выполняться до тех пор, пока текущий узел curr не будет равен nullptr. Внутри цикла функция сохраняет указатель на следующий узел nextNode, меняет указатель на следующий узел текущего узла curr->next на предыдущий узел prev, затем изменяет указатель на предыдущий узел prev на текущий узел curr, а указатель на текущий узел curr на следующий узел nextNode.

После того, как цикл while завершен, указатель на головной узел head изменяется на указатель на последний узел prev (так как prev указывает на последний обработанный узел) и этот указатель возвращается из функции.

Таким образом, функция обращает порядок узлов в связном списке, начиная с указанного узла head, используя итеративный подход.


**reverse_rec**

Эта функция использует рекурсию для обращения связного списка, начиная с узла, указанного в аргументе curr. prev - это указатель на предыдущий узел в списке, изначально равный nullptr.

Функция начинает с проверки, что текущий узел curr не является нулевым указателем, что означает достижение конца списка. Если текущий узел - это конец списка, функция возвращает указатель на предыдущий узел prev, который становится новым началом списка.

Если текущий узел не является концом списка, то функция сохраняет указатель на следующий узел next, меняет ссылку текущего узла на предыдущий узел prev и рекурсивно вызывает себя для обработки следующего узла next с текущим узлом curr. Функция возвращает результат этого рекурсивного вызова.

В итоге, функция обращает связанный список, меняя ссылки узлов в обратном порядке, и возвращает указатель на новый начальный узел.



**len**

Функция len считает длину связного списка, начиная от головного узла (узла с указателем на первый элемент списка) и до последнего узла.

Функция создает указатель на головной узел и переменную len равную 0. Затем, пока указатель на текущий узел не равен nullptr, указатель переходит на следующий узел и переменная len увеличивается на 1.

Когда указатель достигнет конца списка (будет равен nullptr), функция вернет значение переменной len, которое будет равно длине списка.

