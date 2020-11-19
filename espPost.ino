#include <M5StickC.h>
#include <WiFi.h>
#include <HTTPClient.h>

/** Nastav si wifi credentiali podla svojho
 */
const char* ssid = "Fyzika-je-lahka";
const char* pass = "12serenada12";

/** url requestu
 */
const char* serverName = "http://192.168.1.107:1880/espTest";


/** Vyber si pyload aky chces je ich tu viac lebo som cerpal z mojho kodu na test zavyslost casu odosielania
 *  od velkosti requestu
 */
//2kb payload
//const char* payload = "{ \"kZUMqf2gHmh0t4ZXPrWUk3OWSFKtoleuLQIVKgWp9TsGN8o74orFP57wxUrtoIAFSk4uVub5tUmAt54JDIBtwCD9YSjZwG7SejWGLskWHgd5abtq5mrbXpD8S1TR5cdYhDpjfsEDEQ9zAYGn0quGYNTAvmUep6AWu2NkVC4cAcQVBEtCdtesH0Z5nAR9bjvAvOzX7camFX6nEg4yutKEi9fhCNS006IGW3hRVlBfWhFLnMEcPtxJsqI699NS83PwDlw8zlWLGs3plXPEfM96XGMJOxM43pPkaXm2ssBVEptwvaGTShxxADM6fcIpazEW8vdvqXr3Ty2VgEd2uYeZ5GTOlhxWSKE5jFtnz2j3EaO3ls7lzY919XIbXcUQLquUmMxRzNqfu5RssLLu8BJi9dw6j9uCuak5FB8AVwn0lg0xuvx0P4RhdtNShsrgvOFcyr8Hd0o2TGulvVkUCDRypRMCNbxACIXktqR5TlCmBabjM3K2SCB5cHxEELxABN0JfjQKDrqSq1PcC60LxSfPD70qn0UD2l8VFIA1hAOkN0vZll8XrjNdxRCjwmHABEDqYo8ALh4CfUTW1C60dCM0Xca6CUS9idfB9XoU9M\" : \"b1bSEJecgweCIGRly9yvqFPFwhmWG7b0z2kNPYD3RsfVInJuVsnAPv3lnZXXEsOM9BetugdKQLz3ku53SH1GIBKeGTJWy4O853pzy0KfRYGGjxnL6ZREuXRewFpQ40yPzHdkjAoNLfrdRJBcPodTW15LsVGXpgDZJhJHgmNMiUhS3VZ5JFU80IYAjDuULeDPjSjcsAB08BPH2m2o7j8kVuEjeRc454LVqtc6hUJQ0zNAYIBLEcfA2IpfaXKcoRVsruScXkKmh4RmP5iwtEBxGjvf3j5JBTCYbRSXKCnluQ2pTQXIrXaj8qGtR86HQ7zMXAdfSNGGsXObkPKyiRp3R3hiAYtD472rFXGC7xyNHVEU7CJsPZvZc4FuBm6EroABRBakHuILt0BpeLzwlPBuTKVMDuA6ebqToSHM0g9OiVuFUaH8RKptqqbXjPjXq7BBb8KCwDXdEXHCtAu3CNfkg3ENpkJDn1CCdpBIH4zlmAtJHV8qJZGfnSqtjZ5flPj9Pun76lxJ0ZBskQBOUMdJx2Ng5IaJpbVWB81KBhTZpxr9AKhh7CjdzItLImv0ouaTYcuzhzgRkDoLK2VX3smYS4qD6FeGTLgI1Y6CxUIrJTBxoBjDca6v9YlhRJQqEojXjRDZGZappLBbqikJtY5noAGnrdMVyYA5eIQOwtXyj3AuZI1aH3QjZgI1OqEBPYCvPNujQREYG6lqIaf21qeM1VYF0mhFLjtYfGcqjkwPeSKlDXUYUL5jQ7vd07GmCPIDNyen7Kyoy8Bns6Dhvztjj8mScJdUJu9HKLZuVBmnpYmnKfjVZv7Kx8bIPCyRgIAnxEOttvtq8G0xLNmz4MYLDpZME3XXquN3oTRpbadQ5e6mS1Kwcy01MFMG51A5TkOcqcyw6JRyDAqbbSX7BLJohfVolE540qxQ2DQoqpKGvQOHADQrwq4bshFX9OC2Bl6vLgvPCxVZm3G4gNI98XM5D21aMmo01RItcYc6PYRmKZxnW7poSjYop8IlyHzHQkwuu9jQNi9X1y7WB9ZnzGroaMsWuZJ8cXUxlSOSCcbqzSsDCYOk3uL59PBWdchN5anafuddRJVuoqfJZqXLQnJMhLcTVsAl9MQrMqyeVW2p0NMP43esKDGhoL6EQ7Gtsh8R06IdDPfikhBQrzVkH1G9yw87l5ZM0npbIeK6FCedik19hMNe5CUwBZMPUjXsU2OQPdLicaBIl894sqfR08PZCbQBRUaHilKw1z5yUpesluAbWeBgXUV7IitgqYerGQOrpEyPkEaPtrWoispCh3xoYHrwG26dlgjb8kblRQGaN0TebeSFSgCqftUtAZzZbFNJka9hrkAEvgDqNMvoWMmFEEB5DgGiVz\" }";

//1kb payload
//const char* payload = "{ \"1erfV1fPL3D3QaTrZfq2Zn2XWPoH3H9hEBBfdBey6QEW83IB7UHZetUFdxUmVwEpbIzIGA6J8heNuTisZZjyrPvZKLaxhPcgmCY2pEtHQJMdurIm3M4JTqgtvVJQt5jx1zHOxcFGeCmx4JJ6I69VDBOIafxpDkXbxKKiLRfII1UsywKUpeVO2Gn4BUN9cXSLSCvbZtlVcvGB86hHsUOSixGVLEICL4Izri16qVNc24UoDiGehc9i2YmWKfpcNLyCrBQQ09JVVhSRfPX8YaSTUdNu6h5TggxyGvm7acPPkzQVb5vdlxgXU6EyBe7WpQ9CWat9jFXDJwdOdklgOf8d6uOAz972LhU77gZoyq4BtOmaWNjnDuij3OWIhMNn3EWm1dXjSWsI5xzXOT2deaoBTJrrstxoPjXfg5XjYH5ThFOzgQ8btdwwypIjzLnd7kgeiSqSa2RU1jIr7l9K3PUFKjGugiq4vw6iAMrrOLF1c2RzjszCfP8GaFvFctyK653LlVei38PqfTzc2wKgvaHCSWoM4i9budx43WdHTyyUohg0MtEjExElOhijac9O4aPO9KB4WXIsLHhszYxVUJSMhIDqdebsMdxx0Rv3wIKuJkuLC6DNJI99hqG4MGEbW5rTsQxsmo1F7UkvcCDYhZ52MtkNRBRtwhS8pKYoVoPsYnv3GvooWjweDjPIdmrjra7plPEw6awHhjRwd1U80FKfS68J\" : \"kOXRilh906j1UvWvhlSKPfAYn1kZ8sO25wyBL3qnWNb9bBiWhH4Rx66DMHGkW3vf5wgF98dvGdwv1cFkzr5DdPVQHDKKB3WfhFh3DVfKJJJPVAaJDRD48HLfTUXacL0J1btXNk4urIaSUmjOKGpopX5RrctdnqLly3rksqRvb1KiM4hBoI5nbKXfQ1ogUv4Wqop9xHo7UgjA5BGM1yGSyCzJB3Beg6GurUPGEVyPTGcz7hXwiaBgERqx3O25WOSdEtxp\" }";

//500b payload
//const char* payload = "{ \"4SrzUbjw6fWzxbYAHrlHW9GIKBmhhcDLfF3Z0oPhYmJQEBqoRks0GtqCeeCqKKPIWAUoM70uIPGMAwebW9UYvd\" : \"NLh8lzOzvPGNEvpCV7gPe1Lpqz3R21qbQg35oAG3yN7hTmcSrVgnOSdqp5twzuLxujQ2ZnfcGui2duEk0jpU2rh7WHwRJTmHquqZkC6tDmwLE4MCkHJIECBM3ssA0TgRj1enc7go033i0Oz8hfG12yrMtq6YMTQinyG0ogJu3UsaMIruwGnbypncFpRvszCjjsYQMPziDLiAeOxwejIxGMqaEr3iMlqqtTfRjviXtGcDe3Arw1ALk6JGfppCwxRaQEBWJSNXyjV34ZIj73w0mPEjiKRdFevnidckaz2KdXoYYRVttYIul15bQcPdNTOZHoVI9UaqDSqAcRKcpwc3IJQkFQTzI1D00o59sxx55K0NDKu26QHcFpkL3w59cTJhmvenTW1uQVAcuRdZ3FXpBKWIugAXQQ\" }";

//100b payload
const char* payload = "{ \"M7I3GJBcT1qSz8XUtd51vADaaIlezNV1Yj1Za1wb9YTd\" : \"ZBkJstJ2bBIrCkXnPWOVNZYiG5KloC8ad9rW6ZpJeWfx\" }";

void setup(){
    //M5stick init
    M5.begin();

    //screen off
    M5.Axp.ScreenBreath(0);

    //Serial init
    Serial.begin(115200);
    Serial.println("Boot");

    //wifi connect
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, pass);
    while(WiFi.status() != WL_CONNECTED){
        delay(100);
        Serial.print(".");
    }
    Serial.println();
    
    /** message advertisement
     */
    //vytvoris instanciu
    HTTPClient http;

    //nainicializujes komunikaciu smerom na hosta
    http.begin(serverName);

    //dolezity header, bez tohto ti nepojdu data, kukni na nete ake ine body typy to podporuje
    http.addHeader("Content-Type", "application/json");

    //request
    int ret = http.POST(payload);
    //kontrola responsu
    if(ret != 200){
        Serial.printf("ret: %d", ret);
    }

    //koniec
    http.end();
}

void loop(){

}