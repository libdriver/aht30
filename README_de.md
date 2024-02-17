[English](/README.md) | [ 简体中文](/README_zh-Hans.md) | [繁體中文](/README_zh-Hant.md) | [日本語](/README_ja.md) | [Deutsch](/README_de.md) | [한국어](/README_ko.md)

<div align=center>
<img src="/doc/image/logo.svg" width="400" height="150"/>
</div>

## LibDriver AHT30
[![MISRA](https://img.shields.io/badge/misra-compliant-brightgreen.svg)](/misra/README.md) [![API](https://img.shields.io/badge/api-reference-blue.svg)](https://www.libdriver.com/docs/aht30/index.html) [![License](https://img.shields.io/badge/license-MIT-brightgreen.svg)](/LICENSE) 

AHT30 ist ein brandneuer Temperatur- und Feuchtigkeitssensor mit den Vorteilen eines geringen Stromverbrauchs und einer hohen Genauigkeit. Es ist in ein zweireihiges, flaches, bleifreies SMD-Gehäuse eingebettet, das für Reflow-Löten geeignet ist, ein robustes Gehäuse aufweist und klein ist und sich problemlos in schwierige Designs integrieren lässt. Der AHT30 ist mit einem neu optimierten ASIC-spezifischen Chip, einem verbesserten kapazitiven MEMS-Halbleiter-Feuchtigkeitssensorelement und einem standardmäßigen On-Chip-Temperatursensorelement ausgestattet, wodurch seine Leistung erheblich verbessert wurde und eine stabile Leistung auch in rauen Umgebungen aufrechterhalten werden kann. Der Temperatur- und Feuchtigkeitssensor AHT30 kann dazu beitragen, den Stromverbrauch in Anwendungsgeräten zu senken, was ihn äußerst kostengünstig macht. Es eignet sich sehr gut für die Massenproduktion durch Unternehmen, die eine strenge Kostenkontrolle haben, aber auch auf Qualität achten.

LibDriver AHT30 ist der voll funktionsfähige Treiber von AHT30, der von LibDriver gestartet wurde. Er bietet die Funktion zum Lesen von Temperatur und relativer Luftfeuchtigkeit. LibDriver ist MISRA-konform.

### Inhaltsverzeichnis

  - [Anweisung](#Anweisung)
  - [Installieren](#Installieren)
  - [Nutzung](#Nutzung)
    - [example basic](#example-basic)
  - [Dokument](#Dokument)
  - [Beitrag](#Beitrag)
  - [Lizenz](#Lizenz)
  - [Kontaktieren Sie uns](#Kontaktieren-Sie-uns)

### Anweisung

/src enthält LibDriver AHT30-Quelldateien.

/interface enthält die plattformunabhängige Vorlage LibDriver AHT30 IIC.

/test enthält den Testcode des LibDriver AHT30-Treibers und dieser Code kann die erforderliche Funktion des Chips einfach testen.

/example enthält LibDriver AHT30-Beispielcode.

/doc enthält das LibDriver AHT30-Offlinedokument.

/Datenblatt enthält AHT30-Datenblatt.

/project enthält den allgemeinen Beispielcode für Linux- und MCU-Entwicklungsboards. Alle Projekte verwenden das Shell-Skript, um den Treiber zu debuggen, und die detaillierten Anweisungen finden Sie in der README.md jedes Projekts.

/misra enthält die Ergebnisse des LibDriver MISRA Code Scans.

### Installieren

Verweisen Sie auf eine plattformunabhängige IIC-Schnittstellenvorlage und stellen Sie Ihren Plattform-IIC-Treiber fertig.

Fügen Sie das Verzeichnis /src, den Schnittstellentreiber für Ihre Plattform und Ihre eigenen Treiber zu Ihrem Projekt hinzu. Wenn Sie die Standardbeispieltreiber verwenden möchten, fügen Sie das Verzeichnis /example zu Ihrem Projekt hinzu.

### Nutzung

Sie können auf die Beispiele im Verzeichnis /example zurückgreifen, um Ihren eigenen Treiber zu vervollständigen. Wenn Sie die Standardprogrammierbeispiele verwenden möchten, erfahren Sie hier, wie Sie diese verwenden.

#### example basic

```C
#include "driver_aht30_basic.h"

uint8_t res;
uint8_t i;
float temperature;
uint8_t humidity;

res = aht30_basic_init();
if (res != 0)
{
    return 1;
}

...

for (i = 0; i < 3; i++)
{
    aht30_interface_delay_ms(2000);
    res = aht30_basic_read((float *)&temperature, (uint8_t *)&humidity);
    if (res != 0)
    {
        (void)aht30_basic_deinit();

        return 1;
    }
    aht30_interface_debug_print("aht30: temperature is %0.2fC.\n", temperature);
    aht30_interface_debug_print("aht30: humidity is %d%%.\n", humidity); 
    
    ...
        
}

...

(void)aht30_basic_deinit();

return 0;
```

### Dokument

Online-Dokumente: [https://www.libdriver.com/docs/aht30/index.html](https://www.libdriver.com/docs/aht30/index.html).

Offline-Dokumente: /doc/html/index.html.

### Beitrag

Bitte beachten Sie CONTRIBUTING.md.

### Lizenz

Urheberrechte © (c) 2015 - Gegenwart LibDriver Alle Rechte vorbehalten



Die MIT-Lizenz (MIT)



Hiermit wird jeder Person kostenlos die Erlaubnis erteilt, eine Kopie zu erhalten

dieser Software und zugehörigen Dokumentationsdateien (die „Software“) zu behandeln

in der Software ohne Einschränkung, einschließlich, aber nicht beschränkt auf die Rechte

zu verwenden, zu kopieren, zu modifizieren, zusammenzuführen, zu veröffentlichen, zu verteilen, unterzulizenzieren und/oder zu verkaufen

Kopien der Software und Personen, denen die Software gehört, zu gestatten

dazu eingerichtet werden, unter folgenden Bedingungen:



Der obige Urheberrechtshinweis und dieser Genehmigungshinweis müssen in allen enthalten sein

Kopien oder wesentliche Teile der Software.



DIE SOFTWARE WIRD "WIE BESEHEN" BEREITGESTELLT, OHNE JEGLICHE GEWÄHRLEISTUNG, AUSDRÜCKLICH ODER

STILLSCHWEIGEND, EINSCHLIESSLICH, ABER NICHT BESCHRÄNKT AUF DIE GEWÄHRLEISTUNG DER MARKTGÄNGIGKEIT,

EIGNUNG FÜR EINEN BESTIMMTEN ZWECK UND NICHTVERLETZUNG VON RECHTEN DRITTER. IN KEINEM FALL DARF DAS

AUTOREN ODER URHEBERRECHTSINHABER HAFTEN FÜR JEGLICHE ANSPRÜCHE, SCHÄDEN ODER ANDERE

HAFTUNG, OB AUS VERTRAG, DELIKT ODER ANDERWEITIG, ENTSTEHEND AUS,

AUS ODER IM ZUSAMMENHANG MIT DER SOFTWARE ODER DER VERWENDUNG ODER ANDEREN HANDLUNGEN MIT DER

SOFTWARE.

### Kontaktieren Sie uns

Bitte senden Sie eine E-Mail an lishifenging@outlook.com.