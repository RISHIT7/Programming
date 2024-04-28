import sys

class Lexer:
    def __init__(self, in_code_list):
        self.code_list = in_code_list

    def lexing(self):
        
        for line in self.code_list:
            
            line = line.strip()
            if line == "":
                continue

            line += "\n"


            # lexer begin
            token_string = ""
            index = 0
            while index < len(line):    
                
                # comments logic
                if line[index] == "#":
                    while line[index] != "\n":
                        index += 1

                # rest of tokens

                
                # increment
                index += 1

                # printing logic
                token_string += line[index]                
            if token_string.strip() == "":
                continue
            print(token_string, end = "")
            

def main():
    
    filepath = sys.argv[1]
    
    with open(filepath, "r") as f:
        code = f.read()
    f.close()

    code = code.split("\n")
    lexer = Lexer(code)
    lexer.lexing()
    

if __name__ == "__main__":
    main()
