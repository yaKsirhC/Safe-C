#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum states {
    program_none = 0,
    fn_dec = 1,
    eol = -2,
    comment = -3,
};

class ArgumentsNode {
    public:
        vector<string> argnames;
        
        ArgumentsNode() {}
};

class FunctionNode {
    public:
        string fn_name;
        ArgumentsNode args;
        FunctionNode() {}
};

class ProgramState {
    private:
        int currChar;
        string currLine;
        int currPosition = 0;

        int getNextChar(){
            this->currChar = this->currLine[this->currPosition];
            this->currPosition++;
            return this->currChar;
        }
    public:
        states programState;
        string identifier;
        bool beforeIsSpace = false;

        string previousToken = "";
        string currentToken = "";

        FunctionNode FunctionDeclaration;
        ArgumentsNode Arguments;

        void setCurrentLine(string line) {
            this->currLine = line;
            this->currPosition = 0;
            this->getNextChar();
        }

        void getNextToken() {
            if(currChar == ' ' ) {
                getNextChar();
                getNextToken();
                return;
            }
            this->previousToken = this->currentToken;
            this->currentToken = "";
            string tempCurrToken = this->currentToken;

            char gg1 = currChar;
            while(true) {
                char gg = this->currChar;
                if(this->currChar == ' ') {
                    getNextChar();
                    break;
                }

                if(this->currChar == '\0') {
                    programState = eol;
                    break;
                }
                if(this->currChar == '#') {
                    programState = comment;
                    getNextChar();
                    break;
                }
                this->currentToken += this->currChar;

                if(!isalnum(this->currChar)) {
                    if(currentToken.size() > 1){
                        currentToken.pop_back();
                        
                    } else {
                        getNextChar();
                    }
                    break;
                }
                getNextChar();
            }
            // cout << currentToken << endl;
        }

        void printExecState() {
            cout << "\n identifier: " << this->identifier << "\n current Character: " << this->currChar << "\n current Line: " << this->currLine << "\n current Position: " << this->currPosition << "\n program state: " << this->programState << "\n"; 
        }

        void printFunctionState(){
            cout << "\n functionName: " << this->FunctionDeclaration.fn_name << "\n" << "Arguments: ";
            for(int i=0; i < this->Arguments.argnames.size(); i++) {
                cout << this->Arguments.argnames.at(i) << ' ';
            }
            cout << '\n';
        }

        void resetStates(){
            this->programState = program_none;
            this->identifier = "";
            this->beforeIsSpace = false;
        }

        ProgramState() {};
};