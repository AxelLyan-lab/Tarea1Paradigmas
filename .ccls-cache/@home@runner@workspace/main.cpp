#include <iostream>
#include <vector>
using namespace std;

class Pregunta {
private:

    string niveltaxonomia;
    string tipopregunta; 
    string pregunta;             
    string respuesta;            
    int tiempo;

public:

    Pregunta(string niveltaxonomia, string tipopregunta, string pregunta, string respuesta, int tiempo) {
        this->niveltaxonomia = niveltaxonomia;
        this->tipopregunta = tipopregunta;
        this->pregunta = pregunta;
        this->respuesta = respuesta;
        this->tiempo = tiempo;
}

    string getniveltaxonomia(){
        return niveltaxonomia;   // Devuelve el tipo de pregunta y no se usa set porque no queremos asignar un nuevo valor
}

    int gettiempo(){
        return tiempo;        // Devuelve el tiempo asignado y no se usa set porque no queremos asignar un nuevo valor
}

    void Dato() {
        cout << "°°°°°°°°°°°°°°°°°°°°° Dato °°°°°°°°°°°°°°°°°°°°°°" << endl;
        cout << "Nivel de taxonomia: " << niveltaxonomia << endl;
        cout << "Tipo de pregunta: " << tipopregunta << endl;
        cout << "Pregunta: " << pregunta << endl;
        cout << "Respuesta esperada: " << respuesta << endl;
        cout << "Tiempo asignado: " << tiempo << endl;
        cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    }
};

    void mostrarmenu() {
        cout << "°°°°°°°°°°°°°°°°°°°°  MENU °°°°°°°°°°°°°°°°°°°°°°" << endl;
        cout << "1. Crear nueva pregunta" << endl;
        cout << "2. Mostrar todas las preguntas" << endl;
        cout << "3. Buscar preguntas por nivel taxonómico" << endl;
        cout << "4. Calcular tiempo total de evaluación" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: ";
    }

    int main() {
        vector<Pregunta> preguntas; // Vector para almacenar las preguntas permitendo acceder a ellas de forma rapida
        int opcion;
        do {
            mostrarmenu();
            cin >> opcion;
            cin.ignore();

            if (opcion == 1) {
                string niveltaxonomia, tipopregunta, pregunta, respuesta;
                int tiempo;
                int opcionNivel;

                // menu para elegir el nivel de taxonomía
                cout << "1. Seleccione el nivel de taxonomía:\n";
                cout << "   1. Recordar\n   2. Entender\n   3. Aplicar\n   4. Analizar\n   5. Evaluar\n   6. Crear\n";
                cout << "Ingrese el número correspondiente: ";
                cin >> opcionNivel;
                cin.ignore(); // Se usa para limpiar el flujo de entrada despues de algun error de cin/lectura

                switch (opcionNivel) {
                    case 1: niveltaxonomia = "Recordar"; break;
                    case 2: niveltaxonomia = "Entender"; break;
                    case 3: niveltaxonomia = "Aplicar"; break;
                    case 4: niveltaxonomia = "Analizar"; break;
                    case 5: niveltaxonomia = "Evaluar"; break;
                    case 6: niveltaxonomia = "Crear"; break;
                    default:
                        cout << "Opción inválida. Se asignará 'Sin especificar'.\n";
                        niveltaxonomia = "Sin especificar";
                }

                // menu para elegir el tipo de pregunta
                cout << "\n2. Seleccione el tipo de pregunta:\n";
                cout << "   a) Pruebas de composición y ensayo\n";
                cout << "   b) Preguntas de respuesta corta\n";
                cout << "   c) Preguntas de texto incompleto\n";
                cout << "   d) Preguntas de correspondencia o emparejamiento\n";
                cout << "   e) Preguntas de opción múltiple\n";
                cout << "   f) Preguntas de verdadero – falso (justificadas)\n";
                cout << "   g) Preguntas analogías/diferencias\n";
                cout << "   h) Preguntas de interpretación y/o elaboración\n";
                cout << "Ingrese la letra correspondiente: ";
                char letraTipo;
                cin >> letraTipo;
                cin.ignore();         // Se usa para limpiar el flujo de entrada despues de algun error de cin/lectura

                switch (tolower(letraTipo)) {
                    case 'a': tipopregunta = "Pruebas de composición y ensayo"; break;
                    case 'b': tipopregunta = "Preguntas de respuesta corta"; break;
                    case 'c': tipopregunta = "Preguntas de texto incompleto"; break;
                    case 'd': tipopregunta = "Preguntas de correspondencia o emparejamiento"; break;
                    case 'e': tipopregunta = "Preguntas de opción múltiple"; break;
                    case 'f': tipopregunta = "Preguntas de verdadero – falso (justificadas)"; break;
                    case 'g': tipopregunta = "Preguntas analogías/diferencias"; break;
                    case 'h': tipopregunta = "Preguntas de interpretación y/o elaboración"; break;
                    default:
                        cout << "Opcion no valida, se le clasificara como: Sin especificar''.\n";
                        tipopregunta = "Sin especificar";
                }

                cout << "\n3. Ingrese la pregunta: ";
                getline(cin, pregunta);
                cout << "4. Ingrese la respuesta: ";
                getline(cin, respuesta);
                cout << "5. Asigne los minutos para responder: ";
                cin >> tiempo;
                cin.ignore();        // Se usa para limpiar el flujo de entrada despues de algun error de cin/lectura

                preguntas.emplace_back(niveltaxonomia, tipopregunta, pregunta, respuesta, tiempo); // <- LÍNEA AGREGADA

    } else if (opcion == 2) {
        if (preguntas.empty()) {
            cout << "No hay preguntas ingresadas" << endl;
        } else {
            for (size_t i = 0; i < preguntas.size(); ++i)  {  // se usa size_t para enumerar las preguntas y asi mantener un orden
                cout << "Pregunta " << i + 1 << ":" << endl; // se usa i + 1 para que no empiece en 0
                preguntas[i].Dato();
            }
        }

    } else if (opcion == 3) {
        int nivelnum;
        string buscarnivel;

        bool nivelValido = false;

        while (!nivelValido) {
            cout << "\n Seleccione el nivel taxonómico a buscar:" << endl;
            cout << "1. Recordar \n2. Entender \n3. Aplicar \n4. Analizar \n5. Evaluar \n6. Crear" << endl;
            cout << "Ingrese un número del 1 al 6: ";
            cin >> nivelnum;
            cin.ignore();

            switch (nivelnum) {
                case 1: buscarnivel = "Recordar"; nivelValido = true; break;
                case 2: buscarnivel = "Entender"; nivelValido = true; break;
                case 3: buscarnivel = "Aplicar"; nivelValido = true; break;
                case 4: buscarnivel = "Analizar"; nivelValido = true; break;
                case 5: buscarnivel = "Evaluar"; nivelValido = true; break;
                case 6: buscarnivel = "Crear"; nivelValido = true; break;
                default:
                    cout << "\n  Seleccione una opción válida del 1 al 6.\n" << endl;
            }
        }

        bool encontrado = false;
        for (auto& p : preguntas) {
            if (p.getniveltaxonomia() == buscarnivel) {
                p.Dato();
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "No se encontraron preguntas.\n";
        }


    } else if (opcion == 4) {
        int totalTiempo = 0;
        for (auto& p : preguntas) {
            totalTiempo += p.gettiempo();
        }
        cout << "El tiempo ingresado es de: " << totalTiempo << " minutos.\n";


    } else if (opcion == 5) {
        cout << "Saliendo del programa...\n";
    } else {
        cout << "Opción inválida. Intente de nuevo.\n";
    }

    } while (opcion != 5);

        return 0;
}


    
 
        














