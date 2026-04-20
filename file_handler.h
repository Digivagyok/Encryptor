#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

/**
 * @file file_handler.h
 * @brief Fájlkezelő segédosztály.
 */

/**
 * @class FileHandler
 * @brief Fájlok beolvasását és kiírását végzi.
 */
class FileHandler {
public:

    /**
     * @brief Fájl teljes beolvasása.
     */
    static char* readAll(const char* filename);

    /**
     * @brief Fájlba írás.
     */
    static void writeAll(const char* filename, const char* data);
};

#endif
