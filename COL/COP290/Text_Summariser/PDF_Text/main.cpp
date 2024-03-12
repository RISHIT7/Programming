#include <poppler-document.h>
#include <poppler-page.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Replace "example.pdf" with your PDF file name
    const string pdfFileName = "example.pdf";

    poppler::document* doc = poppler::document::load_from_file(pdfFileName);
    
    if (!doc) {
        cerr << "Error loading PDF file: " << pdfFileName << endl;
        return 1;
    }

    for (int pageNum = 0; pageNum < doc->pages(); pageNum++) {
        poppler::page* pdfPage = doc->create_page(pageNum);

        string text = pdfPage->text().to_utf8();

        cout << "Page " << pageNum + 1 << ":\n" << text << endl;

        delete pdfPage;
    }
    delete doc;

    return 0;
}
