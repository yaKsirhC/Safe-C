#include <string>
#include <vector>
#include "read_file.h"
#include "programState.h"

using namespace std;

static ProgramState languageState = ProgramState();

// void parseArgs(){
//     languageState.identifier = "";
//     // int i = 0;
//     while(true) {
//     getNextChar();
//         // if(identifier == "" && currChar)
//         if(isalpha(currChar) || currChar == '_' || ( identifier != "" && isalnum(currChar) ) ){
//             identifier += currChar;
//             // printExecState();
//             continue;
//         }

//         if(currChar == ',') {
//             Arguments.argnames.push_back(identifier);
//             identifier = "";
//             continue;
//         }

//         if(currChar == ' ') continue;

//         if(currChar == ')') {
//             if(identifier != "") {
//                 Arguments.argnames.push_back(identifier);
//                 identifier = "";
//             }
//             break;
//         };

//         cerr << "Syntax Error" << endl;
//         exit(1);
//     }

//     FunctionDeclaration.args = Arguments;
//     // Arguments = ArgumentsNode();

//     printFunctionState();
// }

void parse(){

    while(true){
        languageState.getNextToken();
        cout<< languageState.currentToken << endl;


        if(languageState.programState == comment) {
            languageState.programState = program_none;
            break;
        };
        if(languageState.programState == eol) {
            languageState.programState = program_none;
            break;
        };
    }

}

int main(){
    vector<string> lines = line_read("./first.kos");
    for(string line : lines){
        languageState.setCurrentLine(line);
        parse();

        // currPosition = 0;
    }
    languageState.printExecState();
    return 0;
}