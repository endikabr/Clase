# Tipos de Ficheros y Procesamiento

## **Tipo 1: Fichero con Cabecera de Filas y Columnas, seguido de `unsigned char`**

+----------+ ---------------------------------------------+     
|  FILAS   |               |               |              |
|----------| unsigned char | unsigned char | unsigned char|
| COLUMNAS |               |               |              |
+----------+----------------------------------------------+

- **Descripción:**  
  Contiene una cabecera inicial con las dimensiones de una matriz (filas y columnas). El resto de los elementos son datos de tipo `unsigned char`, organizados fila por fila.

### **Cabecera:**
- `filas` (int): Número de filas.
- `columnas` (int): Número de columnas.

### **Datos:**  
Elementos de tipo `unsigned char`, organizados fila por fila.



### **Acciones:**
1. Leer la cabecera para obtener las dimensiones.
2. Leer los datos fila por fila y procesarlos.

---

## **Tipo 2: Fichero de Elementos de Tipo Estructura, Sin Cabecera**

| Estructura 1 | Estructura 2 | Estructura 3 | Estructura 4 | Estructura 5 |

- **Descripción:**  
  Contiene solo elementos de tipo estructura, sin una cabecera inicial que indique la cantidad de elementos.

### **Cabecera:**  
Ninguna.

### **Datos:**  
Elementos de tipo estructura.


### **Acciones:**
1. Leer y procesar los elementos directamente hasta el final del fichero.
2. Usar un bucle controlado por la función `fread` para leer los elementos.

---

## **Tipo 3: Fichero con Cabecera `numElem`, seguido de Elementos de Tipo Estructura**

| numElem | Estructura 1 | Estructura 2 | Estructura 3 | Estructura 4 | 

- **Descripción:**  
  El primer elemento del fichero es un entero (`numElem`) que indica cuántos elementos hay. El resto son estructuras con los datos.

### **Cabecera:**
- `numElem` (int): Número de elementos.

### **Datos:**  
Elementos de tipo estructura.


### **Acciones:**
1. Leer el número de elementos (`numElem`) desde la cabecera.
2. Leer y procesar cada elemento en un bucle controlado por `numElem`.

---

## **Tipo 4: Fichero con Dos Cabeceras (Filas y Columnas), seguido de `unsigned char`**

| filas | columnas | unsigned char | unsigned char | unsigned char | 

- **Descripción:**  
  Contiene dos enteros iniciales (número de filas y columnas) como cabecera. Los datos son de tipo `unsigned char`, organizados fila por fila.

### **Cabecera:**
- `filas` (int): Número de filas.
- `columnas` (int): Número de columnas.

### **Datos:**  
Elementos de tipo `unsigned char`, organizados fila por fila.

### **Estructura Visual:**
| filas | columnas | unsigned char | unsigned char | unsigned char | 


### **Acciones:**
1. Leer las dos cabeceras (filas y columnas).
2. Leer los datos fila por fila y procesarlos.

---

## **Tabla Resumen**

| **Tipo** | **Descripción**                                                       | **Cabecera**                        | **Datos**                  |
|----------|-----------------------------------------------------------------------|-------------------------------------|----------------------------|
| **1**    | Cabecera con filas y columnas, seguido de `unsigned char`.            | Estructura (`filas` y `columnas`)   | `unsigned char`            |
| **2**    | Solo contiene elementos de tipo estructura, sin cabecera.             | Ninguna                             | Estructura                 |
| **3**    | Cabecera con número de elementos (`numElem`), seguido de estructuras. | Entero (`numElem`)                  | Estructura                 |
| **4**    | Dos enteros iniciales (filas y columnas), seguido de `unsigned char`. | Dos enteros (`filas` y `columnas`)  | `unsigned char`            |

---

## **Consejos para el Examen**
1. **Identificar el Tipo de Fichero:**
   - Examina si tiene cabeceras y qué datos contiene.

2. **Usar `fread` y `sizeof`:**
   - Asegúrate de usar el tamaño correcto para leer cada dato (`sizeof`).

3. **Control de Bucles:**
   - Si hay cabeceras, usa su información para controlar los bucles (filas, columnas, o número de elementos).
   - Si no hay cabecera, lee hasta el final del fichero.

4. **Tipos de Datos:**
   - Para datos de tipo `unsigned char`, muestra los valores como enteros sin signo (`%u`).
Notas: