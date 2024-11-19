# Ejemplo de Ejercicio 1

Codificar un programa que permita la gestión de ficheros con información bidimensional de datos tipo `unsigned char`.

## Tipos de ficheros binarios

### Tipo 1
- **Un solo fichero.**
- Contenido: Listado de ficheros de tipo 2 a gestionar.

#### Formato:
1. **Primer elemento del fichero:**  
   - Un dato de tipo `int` que almacena el número de elementos.
2. **A partir del segundo elemento:**  
   - `nomfich`: Cadena de caracteres de máximo 20 elementos.
   - `codigo`: ?????.

---

### Tipo 2
- **Tantos ficheros como se deseen gestionar.**
- Contienen información bidimensional de datos de tipo `unsigned char`.

#### Formato:
1. **Primer elemento del fichero (estructura):**
   - `filas`: Dato de tipo `int` que indica el número de filas.
   - `columnas`: Dato de tipo `int` que indica el número de columnas.
   - `codigo`: Cadena de caracteres de máximo 12 elementos, que contiene el código de acceso al fichero.
2. **A partir del segundo elemento:**  
   - Cada elemento almacena datos de tipo `unsigned char`.
   - **Nota:** Esta información está almacenada por filas.

---

## Menú del programa

El programa debe ejecutarse con las siguientes opciones:

1. **Salir del programa.**  
2. **Insertar fichero.**  
3. **Eliminar fichero.**  
4. **Comprobar listado.**

---

# Ejemplo de Ejercicio 2

## Opción 1: Insertar fichero
- Introduce el nombre y el código de acceso de un fichero de datos tipo `unsigned char` en el fichero `listado.dat`.

### Detalles:
1. Se pedirá por teclado el nombre del fichero a insertar en el listado.
2. Si el fichero existe, se solicitará el código de acceso al fichero.
3. Si el código de acceso es correcto y el fichero no está en el listado, su información será almacenada en el fichero `listado.dat`.
4. **En caso de error:** Se mostrará la razón en pantalla.

**Nota del profesor:** *Para esto se deben realizar volcados, búsquedas binarias, y otros procesos adicionales.*

---

## Opción 2: Eliminar fichero
- Elimina del fichero `listado.dat` el elemento que contiene el nombre y el código de acceso de un fichero de datos tipo `unsigned char`.

### Detalles:
1. Se pedirá por teclado el nombre del fichero a eliminar.
2. Si el fichero está en el listado, se solicitará el código de acceso.
3. Si el código coincide con el registrado, el elemento será eliminado.
4. **En caso de error:** Se visualizará la razón en pantalla.

---

## Opción 3: Comprobar listado
- Comprueba que todos los ficheros del listado existen y que sus códigos de acceso coinciden con los que figuran en la cabecera de los ficheros de tipo 2.

### Detalles:
1. Para todo fichero que no exista o cuyo código de acceso no coincida:
   - El elemento será eliminado del listado.
   - Se mostrará en pantalla la razón de su eliminación.

---

# Ejemplo de Ejercicio 3

Dado un fichero que contiene el censo de la población bilbaína, se pide escribir un programa que cree un fichero con la información de las personas:
- **Con más de 60 años** o que los cumplan dentro del año actual.

### Requisitos:
- La información no debe borrarse del fichero original.
- El programa debe calcular el porcentaje que representan estas personas respecto al total del censo.

---

## Formato del fichero del censo:
Cada registro contiene los siguientes datos:
- **nombre:** Nombre del ciudadano.
- **dos apellidos:** Apellidos del ciudadano.
- **año de nacimiento:** Año en que nació el ciudadano.
- **dirección:** Dirección del ciudadano.

---

## Funciones del programa:

1. **`programa cReaCenos60`:** Programa principal.  
2. **`creaFichero2(nomFich1, nomFich2)`:**  
   - Crea un nuevo fichero con los datos filtrados.  
3. **`visualizaFichero(nomFich)`:**  
   - Muestra el contenido de un fichero.  
4. **`visualizaFicha(ficha)`:**  
   - Muestra los datos de una ficha individual.
