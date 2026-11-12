# miniRT

Un piccolo ray tracer scritto in C con MiniLibX, per il progetto di 42.
Legge una scena da un file `.rt` e la disegna in una finestra: sfere, piani,
cilindri e coni, con luci colorate, ombre e antialiasing attivabile da tastiera.
Gli oggetti si possono selezionare e modificare anche durante l'esecuzione.

## Compilazione e avvio

Su Linux servono un compilatore C, `make` e le librerie di sviluppo X11,
Xext, readline e ncurses.

```sh
git submodule update --init --recursive
make
./minirt scenes/simple.rt
```

`make clean` elimina i file oggetto, `make fclean` anche l'eseguibile.

## Creare una mappa

Crea un file con estensione `.rt`, con un elemento per riga. Separa i campi
con spazi o tab e usa le virgole per coordinate e colori, senza spazi interni.
Le righe vuote vanno bene; i commenti non sono supportati.

Servono una sola camera (`C`), una sola luce ambiente (`A`) e almeno una luce
(`L`). Puoi aggiungere più luci e più oggetti.

| Sigla | Parametri, in ordine |
| --- | --- |
| `A` | intensità, colore RGB |
| `C` | posizione, direzione, FOV |
| `L` | posizione, intensità, colore RGB |
| `sp` | centro, diametro, colore RGB |
| `pl` | punto sul piano, normale, colore RGB |
| `cy` | centro, direzione dell'asse, diametro, altezza, colore RGB |
| `co` | vertice, direzione dell'asse, angolo, altezza, colore RGB |

Coordinate e direzioni si scrivono come `x,y,z`, i colori come `r,g,b`
(valori interi da 0 a 255). Usa direzioni di lunghezza 1, per esempio `0,0,1`,
con componenti tra -1 e 1. Diametri e altezze devono essere positivi.
Le intensità vanno da 0 a 1: il parser accetta al massimo una cifra decimale,
per esempio `0.3`. Il FOV è un intero tra 0 e 180; `60` è un buon punto di partenza.
L'angolo del cono viene usato in radianti: puoi partire da `0.5`.

Una scena semplice da cui partire:

```text
A 0.2 255,255,255
C 0,0,0 0,0,1 60
L -5,8,0 0.8 255,255,255

sp 0,0,12 4 200,50,50
pl 0,-2,0 0,1,0 180,180,180
cy 5,0,15 0,1,0 2 4 50,100,220
co -5,2,15 0,1,0 0.5 4 220,180,50
```

Salvala, per esempio, in `scenes/mia_scena.rt` e avviala con
`./minirt scenes/mia_scena.rt`. Altri esempi sono in `scenes/`;
`invalid_scenes/` contiene file per provare gli errori del parser.

## Comandi

- **Click sinistro**: seleziona un oggetto.
- **1 / 2**: spostalo a sinistra / destra rispetto alla camera.
- **3 / 4**: spostalo in basso / in alto.
- **5 / 6**: spostalo lungo la direzione della camera / in senso opposto.
- **7 / 8**, **9 / 0**: ruotalo attorno agli assi verticale e orizzontale della camera.
- **Frecce su / giù**: cambia il diametro della sfera, l'altezza del cilindro o l'angolo del cono.
- **Frecce sinistra / destra**: cambia il diametro del cilindro o l'altezza del cono.
- **A**: applica l'antialiasing tramite supersampling.
- **Esc** o chiusura della finestra: esci.

Le modifiche fatte nella finestra non vengono salvate nel file `.rt`.
