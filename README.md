# ESP32 HTTP POST test
## Files
* **espPost.ino** - arduino projekt s post examplom
* **node-red/espFlow.json** - node-red flow pre spracovanie post requestu

## Postup
1. pustis node-red commandom `node-red`

*v terminali*
```
C:\Users\USERNAME> node-red
```

2. pockaj kym ti nabehne

*v terminali*
```
C:\Users\epic_>node-red
20 Nov 00:24:59 - [info]

Welcome to Node-RED
===================

20 Nov 00:24:59 - [info] Node-RED version: v1.2.5
20 Nov 00:24:59 - [info] Node.js  version: v12.16.3
20 Nov 00:24:59 - [info] Windows_NT 10.0.18363 x64 LE
20 Nov 00:25:00 - [info] Loading palette nodes
20 Nov 00:25:00 - [info] Dashboard version 2.22.1 started at /ui
20 Nov 00:25:00 - [warn] ------------------------------------------------------
20 Nov 00:25:00 - [warn] [ttb-node-red-counter/counter] Type already registered
20 Nov 00:25:00 - [warn] ------------------------------------------------------
20 Nov 00:25:00 - [info] Settings file  : \Users\epic_\.node-red\settings.js
20 Nov 00:25:00 - [info] Context store  : 'default' [module=memory]
20 Nov 00:25:00 - [info] User directory : \Users\epic_\.node-red
20 Nov 00:25:00 - [warn] Projects disabled : editorTheme.projects.enabled=false
20 Nov 00:25:00 - [info] Flows file     : \Users\epic_\.node-red\flows_LAPTOP-C47V6NM7.json
20 Nov 00:25:00 - [info] Server now running at http://127.0.0.1:1880/
20 Nov 00:25:00 - [warn]

---------------------------------------------------------------------
Your flow credentials file is encrypted using a system-generated key.

If the system-generated key is lost for any reason, your credentials
file will not be recoverable, you will have to delete it and re-enter
your credentials.

You should set your own key using the 'credentialSecret' option in
your settings file. Node-RED will then re-encrypt your credentials
file using your chosen key the next time you deploy a change.
---------------------------------------------------------------------

20 Nov 00:25:00 - [info] Starting flows
20 Nov 00:25:00 - [info] Started flows
```

3. otvoris si node-red v prehliadaci **local_ip:1880** eg. 192.168.1.107:1880

4. importujes si esp_flow.json

![Image of Menu](https://raw.githubusercontent.com/vtothsvk/espPost/main/images/menu.png)

![Image of Import](https://raw.githubusercontent.com/vtothsvk/espPost/main/images/import.png)

![Image of Click select file](https://raw.githubusercontent.com/vtothsvk/espPost/main/images/click_select.png)

![Image of Select file](https://raw.githubusercontent.com/vtothsvk/espPost/main/images/select_file.png)

* **dany json najdes na repe node-red/espFlow.json**

![Image of Import flow](https://raw.githubusercontent.com/vtothsvk/espPost/main/images/import_file.png)

* mal by ti tam naskocit tieto nody

![Image of flow](https://raw.githubusercontent.com/vtothsvk/espPost/main/images/flow.png)

5. deploy

![Image of Deploy](https://raw.githubusercontent.com/vtothsvk/espPost/main/images/deploy.png)

6. prejdi si kod a dopln/prepis co treba

```C++
/** Wifi credentials
 * 
 *  @note nastav si podla svojho
 */
const char* ssid = "Fyzika-je-lahka";
const char* pass = "sizmajbit";

/** url requestu
 * 
 *  @note nastav si podla sojej IP
 *  @note na porte 1880 bezi node-red nativvne, tj port nemen
 *  @note /espTest endpoint je dany "http in" nodom v node-rede (tym vlavo) keby si ho chcel nahodou zmenit
 */
const char* serverName = "http://192.168.1.107:1880/espTest";
```

7. nahraj a kukaj debug v node-rede

![Image of debug](https://raw.githubusercontent.com/vtothsvk/espPost/main/images/debug.png)

* mal by ti tam nabehnut takyto zazrak ked ESP posle request

![Image of message](https://raw.githubusercontent.com/vtothsvk/espPost/main/images/payload.png)
