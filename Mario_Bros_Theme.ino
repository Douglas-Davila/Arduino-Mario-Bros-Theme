// Pino de saída para o circuito de reprodução da música
const int pinoAltoFalante = 8;

// Definição das frequências das notas musicais
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_A3  470
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698 
#define NOTE_G5  784
#define NOTE_A5  880 

// Sequência de notas da melodia da música tema de Mário Bros
int melodia[] = {
  NOTE_E5, 0, NOTE_E5, 0, 0, NOTE_E5, 0, 0, NOTE_C5, NOTE_E5, 0,
  NOTE_G5, 0, 0, 0, NOTE_G4, 0, 0, 0,
  NOTE_C5, 0, 0, NOTE_G4, 0, 0, NOTE_E4, 0,
  0, NOTE_A4, 0, NOTE_B4, 0, NOTE_A3, NOTE_A4, 0,
  NOTE_G4, NOTE_E5, 0, NOTE_G5, NOTE_A5, 0, NOTE_F5, NOTE_G5,
  0, NOTE_E5, 0, NOTE_C5, NOTE_D5, NOTE_B4, 0
};

// Duração de cada nota
int duracoes[] = {
  8, 6, 8, 6, 6, 6, 8, 6, 6, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4
};

int notaInicial = 0; 

// Conta quanto vezes a música foi tocada
int vezesTocadas = 0;

void setup() {
  pinMode(pinoAltoFalante, OUTPUT);
}

void loop() {
  // Verificando se a música tocou menos de 3 vezes
  if (vezesTocadas < 3) {
    
    int tamanhoMusica = sizeof(melodia) / sizeof(int);

    // Varre as notas a partir da notaInicial configurada
    for (int notaAtual = notaInicial; notaAtual < tamanhoMusica; notaAtual++) {

      int duracaoNota = 500 / duracoes[notaAtual];
      
      if (melodia[notaAtual] != 0) {
        tone(pinoAltoFalante, melodia[notaAtual], duracaoNota);
      } else {
        noTone(pinoAltoFalante); 
      }

      int pausaEntreNotas = duracaoNota * 1.30;
      delay(pausaEntreNotas);
    }

    // Configuração para recomeçar a música a partir da 19º nota, após a 1º reprodução
    notaInicial = 19; 
    
    // Adiciona 1 ao contador após terminar de rodar a música
    vezesTocadas++; 

    // Tempo de espera para reproduzir novamente a música
    delay(100);
    
  } else {
    // Após tocar 3 vezes, o som é interrompido no pino de saída (Arduino mudo!)
    noTone(pinoAltoFalante);
  }
}