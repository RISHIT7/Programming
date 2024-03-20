import sys
from pypdf import PdfReader

def main():
    filename = sys.argv[2]
    reader = PdfReader(filename)
    pages = reader.pages

    with open('text.txt', 'w') as file:
        for i in range(len(pages)): 
            page = pages[i]
            file.write(page.extract_text())
            file.write('\n')
    file.close()

if __name__ == "__main__":
    main()