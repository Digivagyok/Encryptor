#ifndef ARGUMENT_PARSER_H
#define ARGUMENT_PARSER_H

/**
 * @file argument_parser.h
 * @brief Parancssori argumentum feldolgozó.
 */

/**
 * @class ArgumentParser
 * @brief CLI argumentumok feldolgozásáért felel.
 */
class ArgumentParser {
private:
    const char* algorithm;
    const char* input;
    const char* output;
    int key;
    bool help;

public:
    ArgumentParser(int argc, char* argv[]);

    const char* getAlgorithm() const;
    const char* getInput() const;
    const char* getOutput() const;
    int getKey() const;
    bool isHelp() const;
};

#endif
