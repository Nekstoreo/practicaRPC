# Proyecto Sumador RPC

Este proyecto implementa un servicio RPC (Remote Procedure Call) que suma una lista de hasta 10 números enteros. El proyecto incluye tanto el servidor como el cliente para interactuar con el servicio.

## Requisitos

Para compilar y ejecutar este proyecto, necesitas tener instalados los siguientes paquetes:

### Fedora

```sh
sudo dnf install gcc rpcgen rpcbind libtirpc-devel
```

### Ubuntu

```sh
sudo apt-get install gcc rpcbind libc6-dev libtirpc-dev
```

## Compilación

Para compilar el proyecto, sigue estos pasos:

1. Genera los archivos de código fuente RPC usando `rpcgen`:

   ```sh
   rpcgen sumador.x
   ```

2. Compila los archivos generados y los archivos fuente del proyecto:

   ```sh
   gcc -I/usr/include/tirpc -o sumador_clnt sumador_clnt.c sumador_xdr.c main.c -ltirpc
   gcc -I/usr/include/tirpc -o sumador_svc sumador_svc.c sumador_xdr.c sumador_impl.c -ltirpc
   ```

## Ejecución

### rpcbind

Antes de ejecutar el servidor, asegúrate de que el servicio `rpcbind` esté en ejecución:

```sh
sudo systemctl enable rpcbind
sudo systemctl start rpcbind
```

### Servidor

Para ejecutar el servidor, usa el siguiente comando:

```sh
./sumador_svc
```

### Cliente

Para ejecutar el cliente y enviar una lista de números para sumar, usa el siguiente comando:

```sh
./sumador_clnt num1 num2 ... num10
```

Por ejemplo:

```sh
./sumador_clnt 1 2 3 4 5
```

## Estructura del Proyecto (y archivos generados)

- `sumador.x`: Archivo de definición RPC.
- `main.c`: Programa principal del cliente.
- `sumador_impl.c`: Implementación de la función remota para el servidor.

## Notas

- Asegúrate de que el servidor RPC esté en ejecución antes de ejecutar el cliente.
- El cliente y el servidor deben ejecutarse en la misma máquina o en máquinas que puedan comunicarse entre sí a través de la red.
