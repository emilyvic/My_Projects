#Proyecto Integrador de Programación.
#Autor: Emilia Jácome

#Construcción del Tablero
def tablero_inicial(dimen): #Esta función construye la matriz del tablero del juego.
    lista=[" ",]
    matriz =[]
# Fila 1 (números de referencia)
    for fila1 in range (dimen):
        lista.append(fila1)
    matriz.append(lista)
#Filas 1-3
    for fila3 in range (dimen-1):
        lista =[]
        lista.append (fila3)
        for j in range (dimen):
            lista.append ("$")   
        matriz.append(lista)
#Fila 4
    lista=[]
    for fila4 in range (dimen+1):
        if fila4 == 0:
            lista.append(dimen-1)
        elif fila4 == 1 or fila4 == dimen:
            lista.append("-")
        else:
            lista.append("$")   
    matriz.append(lista)
    return matriz


def mostrar_tablero(matriz):#Mostrar el tablero en forma de cuadrado
    tam = len(matriz)
    for i in range (tam):
        #Para cada fila
        for j in range (tam):
            #El valor de cada columna
            print (matriz[i][j],end=" ")
        print ("")

def condiciones_coordenadas(reg,dimen,col,matriz):
    coordenadas = True
    #test 1
    if reg > dimen or reg < 1 or col > dimen or col < 1:
        coordenadas = False
    #test 2
    elif matriz[reg][col]!="$":
        coordenadas = False
    return coordenadas

def pedir_direccion(): #Esta función pide la dirección a la que quiere mover la ficha el usuario.
    direc = ""
    while direc != "a" and direc != "w" and direc != "d" and direc != "s":
        print ("""Digite la dirección:
        w = arriba
        s = abajo
        a = izquierda
        d = derecha""")
        direc = input()
    return direc

def condiciones_movimiento(reg, col, direc, dimen, matriz):#Esta función analiza si
    #las coordenadas que introdujo el usuario y la dirección que especificó son posibles y correctas de acuerdo al juego
    movimiento= True
    #test3: Movimientos fuera del tablero
    if ((reg== 1 or reg == 2 ) and direc == "w") or\
     ((reg == dimen-1 or reg == dimen) and direc == "s") or\
     ((col == 1 or col == 2) and direc == "a") or \
     ((col == dimen-1 or col == dimen) and direc == "d"):
        movimiento = False
    #test4: Movimiento cuando la pieza siguiente no tenga ficha
    elif (direc == "w" and matriz[reg-1][col] != "$") or\
         (direc == "s" and matriz[reg+1][col] != "$") or\
         (direc == "a" and matriz[reg][col-1] != "$") or\
         (direc == "d" and matriz[reg][col+1] != "$"):
        movimiento = False
    #test5_ Movimiento cuando se quiere mover una pieza a un recuadro que está ocupado.
    elif (direc == "w" and matriz[reg-2][col] != "-") or\
         (direc == "s" and matriz[reg+2][col] != "-") or\
         (direc == "a" and matriz[reg][col-2] != "-") or\
         (direc == "d" and matriz[reg][col+2] != "-"):
        movimiento = False
    return movimiento

def movimiento (reg, col, direc, matriz): # Esta función efectúa el movimiento dictado por el usuario.
    matriz[reg][col] = "-"
    #Para abajo
    if direc == "s":
        matriz[reg+2] [col] = "$"
        matriz[reg+1] [col] = "-"
        
    elif direc =="w":
        #Para arriba
        matriz[reg-2][col] = "$"
        matriz[reg-1] [col] = "-"
        
    elif direc =="d":
        #Para derecha
        matriz[reg][col+2] ="$"
        matriz[reg][col+1] ="-"
    else:
        matriz[reg][col-2] ="$"
        matriz[reg][col-1] ="-"
    return matriz

def preguntar (): #Esta función pregunta al usuario si desea continuar jugando.
    respuesta = " "
    while respuesta != "s" and respuesta != "n":
        print("¿Desea continuar con el juego?")
        respuesta = input()
    if respuesta == "s":
        ans = True
    else:
        ans = False
    return ans

def cuenta_espacios(matriz,cant_casillas): #Esta función determina si el usuario ganó o perdió la partida después de que haya especificado que quiere terminar de jugar.
    espacios = 0
    for reg in range (len(matriz[0])):
        for col in range (len(matriz[0])):
            if matriz[reg][col] == "-":
                espacios += 1
    return espacios

def main(): #función principal del juego
    #sin contar las referencias de las casillas, puedes cambiar la dimensión si quieres.
    DIMEN = 4 
    cant_casillas = DIMEN**2
    tablero = tablero_inicial(DIMEN)
    jugar = True
    
    while jugar == True:
        mostrar_tablero(tablero)
        print("Reglón:")
        reg_tab = int(input())
        reg = reg_tab+1
        # Por la diferencia en la cuenta de reglones y columnas que se muestra en el tablero y los reales.
        
        print("Columna:")
        col_tab = int(input())
        col = col_tab +1
        #Por la diferencia en la cuenta de reglones y columnas que se muestra en el tablero y los reales.
        
        coordenadas_permitidas = condiciones_coordenadas(reg,DIMEN,col,tablero)
        if coordenadas_permitidas == True:
            direccion = pedir_direccion()
            movimiento_permitido = condiciones_movimiento(reg, col, direccion, DIMEN, tablero) 
        
    #Volver a pedir los datos en caso de que las coordenadas o el movimiento sea incorrecto.
        while (coordenadas_permitidas== False) or (movimiento_permitido == False):
            print("")
            print("Movimiento inválido, vuelva a intentar")
            print("")
            mostrar_tablero(tablero)
            
            print("Reglón:")
            reg_tab = int(input())
            reg = reg_tab+1
            
            print("Columna:")
            col_tab = int(input())
            col = col_tab+1
            
            coordenadas_permitidas = condiciones_coordenadas(reg,DIMEN,col,tablero)
        
            if coordenadas_permitidas == True: 
                direccion = pedir_direccion()
                movimiento_permitido = condiciones_movimiento(reg, col, direccion, DIMEN, tablero) 
        
        tablero = movimiento(reg, col, direccion, tablero)
        #Imprimir el tablero
        mostrar_tablero(tablero)
        #Preguntar al usuario si desea continuar jugando
        jugar = preguntar() 
    print("FIN DEL JUEGO")
    
    cant_espacios = cuenta_espacios(tablero, cant_casillas)
    if cant_espacios == cant_casillas-1:
        print ("Juego Ganado!!")
    else:
        print("Juego perdido. Siga intentando")
            
main()
