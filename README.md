# Proyecto de Optimización de Red de Internet

## Materia
Análisis y diseño de algoritmos avanzados (Gpo 604)

## Integrantes del Equipo
- Edsel De Jesus Cisneros Bautista - A00838063
- Abdiel Fritsche Barajas - A01234933
- Miguel Mendoza Jaidar - A01234354
- Daniel Rubies Isla - A00832425

## Descripción del Proyecto
Este proyecto implementa una solución integral para una empresa que desea incursionar en los servicios de Internet. El programa resuelve cuatro problemas fundamentales utilizando diferentes algoritmos de optimización:

### 1. Optimización de Cableado (Algoritmo de Kruskal)
- Determina la forma óptima de conectar colonias con fibra óptica
- Minimiza la distancia total del cableado
- Asegura que todas las colonias estén interconectadas

### 2. Ruta de Servicio (Problema del Viajero Vendedor)
- Calcula la ruta más eficiente para entregar documentación física
- Visita cada colonia exactamente una vez
- Retorna al punto de origen
- Identifica las colonias con letras (A, B, C, etc.)

### 3. Análisis de Flujo de Datos (Algoritmo de Ford-Fulkerson)
- Calcula el flujo máximo de información entre nodos
- Considera las capacidades máximas de transmisión
- Toma en cuenta interferencias electromagnéticas

### 4. Ubicación de Centrales (Búsqueda Lineal)
- Determina la central más cercana para nuevas conexiones
- Maneja múltiples centrales por colonia
- Utiliza coordenadas geográficas para los cálculos




## Estructura del Código
- `Edge`: Estructura para representar aristas del grafo
- `Point`: Estructura para manejar coordenadas
- `DisjointSet`: Clase para implementar el algoritmo de Kruskal
- Funciones principales:
  - `kruskal()`: Implementación del algoritmo de Kruskal
  - `tsp()`: Solución del Viajero Vendedor
  - `fordFulkerson()`: Implementación de Ford-Fulkerson
  - `findNearestCenter()`: Búsqueda de central más cercana



## Notas Adicionales
- Las matrices de entrada deben ser cuadradas y simétricas
- Los valores de distancia y capacidad deben ser no negativos
- Se asume que todas las colonias son accesibles
- El programa no verifica la validez de las coordenadas geográficas