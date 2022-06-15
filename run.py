#!/usr/bin/python3

# Este script es un ejemplo de como medir tiempos utilizando python.
# Pueden utilizar este script para resolver el cuarto ejercicio del TP.

import subprocess
import datetime

# (1) Declaro los casos a ejecutar
results = {"./sortProcess1.out": [], "./sortProcess2.out": [], "./sortProcess4.out": [] }

# (2) Ejecuto multiples veces cada uno de los programas midiendo cuanto demoran en ejecutar
for prog in results.keys():
    for i in range(1,100):        
        start = datetime.datetime.now()
        run = subprocess.Popen([prog])
        run.wait()
        end = datetime.datetime.now()
        diff = (end - start).total_seconds()
        results[prog].append(diff)

# (3) Imprimo los resultados del experimento
for key in results:
    m = min(results[key])
    print("{}: {}".format(key,m))


    

