// Existing code ...

// Include LittleFS library if not already included
#include <LittleFS.h>

// Existing setup code ...

void setup() {
    // Existing setup code ...
    LittleFS.begin(); // Initialize LittleFS

    // Existing server setup code ...
}

// Existing loop code ...

// New route for creating directories
server.on("/mkdir", HTTP_POST, [](AsyncWebServerRequest *request) {
    if (!request->hasParam("dir", true)) {
        request->send(400, "text/plain", "Missing 'dir' parameter.");
        return;
    }
    String dirName = request->getParam("dir", true)->value();
    if (LittleFS.mkdir(dirName)) {
        request->send(200, "text/plain", "Directory created: " + dirName);
    } else {
        request->send(500, "text/plain", "Failed to create directory: " + dirName);
    }
});

// Existing server handling code ...
