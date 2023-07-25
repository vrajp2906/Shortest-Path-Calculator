# Shortest-Path-Calculator

In this project we are going to build a software solution for the computation of the shortest path from one place to another place in a two dimensional space; similar to a global positioning system (GPS).

The vision of the project is that given the map of a region and the road connectivity of the region, we would like to compute the shortest path to go from one place to another place.

* The cities will be arranged in a rectangular two dimensional array pattern with certain number of rows and columns; similar to a matrix object.
* Each city will be connected only to its adjacent cities to the right, left, above and below. No other connectivity will be allowed.
* A city may or may not be connected to its adjacent city; for example if there is no road linking a city to a city to its right, left, above or below.
* The cost of the connections will be provided.
* The project will compute and print all possible paths from a given departure city to a given destination city with the restriction that a loop is not permitted.
* In order to make the computation of all paths manageable, the connectivity of cities will be sparse; that is there will be few available connectivity.
