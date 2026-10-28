# Grundlagen der Systemnahen Programmierung - Praktikum

## Testfälle

| Eingabe                       | Erwartungswert           | Ergebnis |
| ----------------------------- | ------------------------ | -------- |
| `7 * 0`                       | `0`                      |          |
| `42 / 0`                      | `0`                      |          |
| `2147483646 + 1`              | `2147483647`             |          |
| `0 - 1`                       | `-1`                     |          |
| `0 / 1`                       | **Error Zero Div**       |          |
| `INT_MAX32 + 1`               | **Error Overflow**       |          |
| `1 e 1 e 1 e … e` (21× `1 e`) | **Error Stackoverflow**  |          |
| `p`                           | **Error Stackunderflow** |          |
| `e`                           | **Error Unexpected**     |          |

## Modulkonzept

[Modulkonzept](./gs_1.png)

Das Modul `tokenhandler` verarbeitet die Tokens. Tokens werden durch Displayeingaben erzeugt. Hier wird er verarbeitet, die jeweiligen Operationen in den anderen Modulen, werden je nach Anweisung angestoßen.
Hier ist die Schnittstelle für die Fehlerbehandlung der Funktionen. Diese wird auch hier angestoßen.

Das Modul `alu` implementiert alle Rechnungen, die der Taschenrechner anbietet. Hier werden die Integer-Operationen gemacht.

Das Modul `stack`implementiert den Speicher. Informationen und Operationen werden hier zusammen verwaltet.

Das Modul `errorhandler` macht die Fehlerbehandlung von allen Modulen. Die Module reichen über den tokenhandler die jeweiligen Fehlercodes weiter.