# Laboratorio 01: Configuración de Entorno y Fundamentos de C para Sistemas Operativos (IS-380)

**Universidad Nacional de San Cristóbal de Huamanga**  
**Escuela Profesional de Ingeniería de Sistemas**  
**Asignatura:** Sistemas Operativos (IS-380)  
**Docente:** Ing. Leydy Rosmery Maldonado Chauca  

---

## 1. Objetivos
* Configurar un entorno de trabajo con sistemas operativos Linux (Ubuntu) sobre Windows mediante WSL, como entorno base para el trabajo a lo largo del curso.
* Instalar y verificar el funcionamiento del compilador de lenguaje C dentro del entorno configurado.
* Aplicar los fundamentos de C relevantes para sistemas operativos: punteros y estructuras (`structs`).

---

## 2. Equipos y Materiales
* Computadora con Windows 10 (versión 2004 o superior) o Windows 11.
* WSL 2 (Windows Subsystem for Linux).
* Git y GitHub para el control de versiones.
* Herramientas de software utilizadas:
  * **Ubuntu** (Distribución Linux)
  * **GCC** (`build-essential`)
  * Editor de texto en consola (`nano`)
  * Terminal del sistema (PowerShell y terminal de Ubuntu)

---

## 3. Fundamento Teórico

### 3.1. Virtualización y necesidad de un entorno Linux
Los sistemas operativos no pueden administrar de manera simultánea el mismo hardware físico de forma nativa sin interferir entre sí. Para solucionar esto se emplea una **máquina virtual**, simulando un entorno de hardware por software que permite ejecutar un sistema operativo distinto sobre el sistema anfitrión. **WSL (Windows Subsystem for Linux)** implementa este mecanismo permitiendo ejecutar un entorno virtualizado Ubuntu sobre Windows.

### 3.2. Jerarquía de virtualización
1. **Hardware real**
2. **Windows** (administra el hardware real)
3. **Máquina virtual** (WSL2 / Hyper-V)
4. **Ubuntu** (se ejecuta en este nivel)
5. **QEMU** (máquina virtual adicional, Laboratorio 02)
6. **xv6** (sistema operativo educativo que se ejecuta sobre QEMU)

### 3.3. Fundamentos de C aplicados a sistemas operativos
* **Punteros:** Variables que almacenan direcciones de memoria en lugar de valores directos. xv6 los utiliza de manera extensiva para la gestión de procesos y memoria.
* **Estructuras (`structs`):** Agrupan variables relacionadas bajo un mismo nombre. xv6 representa procesos, archivos y recursos mediante estructuras.

---

## 4. Actividades de Laboratorio

### 4.1. Verificación de la versión de Windows
* **Comando:** `Windows + R` y escribir `winver`.
* **Requisito:** Windows 10 (versión 2004, compilación 19041 o superior) o Windows 11.

### 4.2. Verificación de virtualización de hardware
* **Comando en PowerShell:** `systeminfo`.
* **Validación:** Buscar la sección "Requisitos de Hyper-V" y confirmar que *"Se habilitó la virtualización en el firmware"* indique **Sí**.

### 4.3. Instalación de WSL y Ubuntu
1. **Verificar distribución existente:** Ejecutar en PowerShell `wsl --list --verbose`.
2. **Instalación:** Ejecutar en PowerShell con privilegios de administrador:
   ```powershell
   wsl --install -d Ubuntu
3. **Crear y acceder al directorio de trabajo:** 
   ```bash
   mkdir so-lab01
   cd so-lab01
## 5. Ejercicio Práctico: Simulador de Planificador de Procesos

Como aplicación práctica de los fundamentos de C y la gestión de memoria en sistemas operativos, se desarrolló un simulador simplificado de planificación por prioridades en un archivo denominado `lab01.c`.

#### A. Definición de la Estructura de Procesos
Se modeló la estructura básica que los núcleos de sistemas operativos (como xv6) emplean para administrar los atributos de un proceso:
```c
struct Proceso {
    int pid;             // Identificador único del proceso
    char nombre[20];     // Nombre descriptivo
    int prioridad;       // Prioridad de 1 (alta) a 5 (baja)
};
