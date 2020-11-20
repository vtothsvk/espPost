# ESP32 HTTP POST test
## Files
* **espPost.ino** - arduino projekt s post examplom
* **node-red/esp_flow.json** - node-red flow pre spracovanie post requestu

## Node-red
1. pustis node-red commandom `node-red`

*v terminali*
```
C:\Users\USERNAME> node-red
```

2. otvoris si node-red v prehliadaci **local_ip/1880** eg. 192.168.1.107:1880

3. importujes si esp_flow.json

4. prejdi si kod a dopln/prepis co treba

```C++
/** Wifi credentials
 * 
 *  @note nastav si podla svojho
 */
const char* ssid = "Fyzika-je-lahka";
const char* pass = "12serenada12";

/** url requestu
 * 
 *  @note nastav si podla sojej IP
 */
const char* serverName = "http://192.168.1.107:1880/espTest";
```

5. nahraj a kukaj debug mal by ti prist takyto pekny json
