Se dispone de unos ficheros binarios de datos cuyos nombres son F01, f02, f04, f015, f20. Es decir, los nombres contienen 3 caracteres, el primero de ellos es una f y los otros datos son caracteres numéricos de tal manera que se podrían disponer hasta un máximo de 99 ficheros. Se sabe que el nombre del primer fichero es f01, pero los dos caracteres numéricos del nombre del resto de ficheros no son necesariamente correlativos. Los elementos de dichos ficheros son de tipo unsigned char.

Se pide realizar un programa que realice las siguientes operaciones sin intervención del usuario, es decir, el usuario no puede insertar ninguna información desde el teclado.

Operación 1
Calculará para el primer fichero, cuyo nombre es f01, el valor numérico que más se repite y el número de repeticiones de dicho valor, visualizando dicha información en pantalla según el formato que aparece a continuación. Se sabe que ningún valor se repite más de 255 veces. Formato de visualización:

css
Copiar código
nombre del fichero, valor que más se repite, número de repeticiones;
Ejemplo:

Copiar código
f01, 109, 111;
Operación 2
Calculará para el primer fichero, cuyo nombre es f01, el valor numérico que menos se repite (y que aparezca al menos una vez) y el número de repeticiones de dicho valor, visualizando dicha información en pantalla según el formato que aparece a continuación. Se sabe que ningún valor se repite más de 255 veces.

Operación 3
Ayudándonos de funciones ya definidas para la operación 1, calculará para todos y cada uno de los ficheros el valor numérico que más se repite y el número de repeticiones de dicho valor, almacenando dicha información en un fichero binario de datos cuyo nombre es RESULTS1. Se sabe que ningún valor se repite más de 255 veces. Los elementos del fichero RESULTS1 son de tipo unsigned char y almacenarán la información según el siguiente formato:

En primer lugar, el valor que más se repite en el fichero f01.
A continuación, el número de repeticiones del valor anterior.
Le sigue el valor que más se repite en el siguiente fichero (en orden ascendente según el nombre).
A continuación, el número de repeticiones del valor anterior.
Y así sucesivamente hasta completar todos los ficheros que se disponen.

Operación 4
Ayudándonos de funciones definidas para la operación 2, calculará para todos y cada uno de los ficheros el valor numérico que menos se repite (y que aparezca al menos una vez) y el número de repeticiones de dicho valor, almacenando dicha información en el fichero binario de datos cuyo nombre es RESULTS2. Se sabe que ningún valor se repite más de 255 veces. Los elementos del fichero RESULTS2 son de tipo unsigned char y almacenarán la información según el siguiente formato:

Operación 5
Teniendo en cuenta todos los ficheros, calculará el valor numérico que más se repite y el número de repeticiones de dicho valor, visualizando dicha información en pantalla según el formato que aparece a continuación. Se sabe que ningún valor se repite más de 255 veces. Formato de visualización:

Copiar código
valor que más se repite, número de repeticiones;
Se visualizará en tantas líneas como valores haya con el máximo valor de repeticiones.

Operación 6
Teniendo en cuenta todos los ficheros, calculará el valor numérico que menos se repite (y que aparezca al menos una vez) y el número de repeticiones de dicho valor, visualizando dicha información en pantalla según el formato que aparece a continuación. Se sabe que ningún valor se repite más de 255 veces. Formato de visualización:

valor que menos se repite, número de repeticiones;
Se visualizará en tantas líneas como valores haya con el mínimo de repeticiones.

Nota
Los nombres de los ficheros binarios de entrada deben generarse automáticamente a partir del nombre del fichero F01.
No se permite el uso de funciones de biblioteca que conviertan cadenas de caracteres a números, o números a cadenas de caracteres.


////fucnion a la que le pasanos el nombre de fichero y nos devuelve el numero que mas se repite y el numero de repeticiones. no se debe contemplar que haya varios valores que mas se rrepiten si el examen nos nos los dice funcion qeu crea un array de contadores. funcion cuenta valro que le pasameos el nombre del ficheor y la direccion de comienzo del array, esa funcion abre el fichero qcon un if y lo recore while fread != 0, leemos un elementos y lo colocamos en el array de contadolres y incrementamos una unidad, por ultimo un fclose para cerrrar el fichero. esa funcion busca moda llamaria a una funcoin busca maximo a la cual le pasamos la direccion de comikenzo del array

main{

buscaModa(nomFich, m, rep){ 


reservaMemoria(){ 
}

cuentaValores(){
///usar while fread != 0 para pasearse por el array
}

cuentaMaximo(){

}

liberaMemoria(){

}
}   


}

