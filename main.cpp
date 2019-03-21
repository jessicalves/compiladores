#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Erro {
	int linha_erro;
	char caractereErro;
	Erro(int l, char c) : linha_erro(l) ,caractereErro(c) {
	}
};

class Parser {
	public:
	int linha_atual;
	string alfabeto;
	vector<Erro> erros;
	Parser() {
		alfabeto = "abcdefghijklmnopqrstuvwxyz_";
	}
	void parse();
	void salvarErros();
	~Parser(){
		erros.clear();
	}
};


void Parser::parse() {
	string line;
	string palavra;
	while(getline(cin, line)) {
		stringstream ss(line);
		while(ss >> palavra){
			for(int i = 0; i < palavra.size(); i++){
				if(alfabeto.find(palavra[i]) == std::string::npos){
					//verificacao de tokens
				}
				else {
					erros.push_back(Erro(linha_atual, palavra[i]));
				}
			}
		}
		linha_atual++;
	}
}

void Parser::salvarErros() {
	freopen("erros.txt", "w", stdout);
	if(erros.size() > 0) {
		cout << "Erro:\n";
		for(int i = 0; i < erros.size(); i++){
			cout << erros[i].linha_erro << ": " << erros[i].caractereErro << " invalido.\n";
		}
		std::fclose(stdout);
	}
}

int main()
{
    freopen("entrada.txt", "r", stdin);

    Parser p;
    p.parse();
    
    
    
}
