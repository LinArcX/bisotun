# bisotun
A simple & minimal wrapper library around [PDFGen](https://github.com/AndreRenaud/PDFGen) to generate resume/books/documents more easily.

# why?
Sometimes i need to generate PDF files. like to write my resume. there are some options avilable:
1. using microsoft word to write your doc and export a pdf file.
2. use typesetting systems like Tex/Latex, groff/troff/nroff, etc..
3. use online websites.

I tested all of the above options, but none of them were my favorite. The values that i prefer:
- having a tool/solution to generate a PDF in a simpleset/minimal manner.
- having 100% control over my tools.
  - maybe just number 2 can give this, because you think it's free & open-source? have a good time to fully understand it.
  - i don't want to talk about online tools :) you don't even know what's happening behind the scene.
- Tex/Latex is huge. there are some minimal installations media which stripped down the size of it. but it's still a lot for just generating a document.
  - And it's not only about the size it occuped on your disk. it has a package manager with lots of dependencies. come on! i want to generate just a pdf.
  - i don't care about different file format that we can generate in Tex/Latex. the only type of file which i care is PDF.

# structure of the repo
To use biston , you need to copy:
- `bisotun.c`
- `bisotun.h`
- `PDFGen/pdfgen.c`
- `PDFGen/pdfgen.h`
into your project's directory. there's a example directory that you can find how to use the library.

# examples
In __example/__ directory, you can find __resume.c__ which is currently created as a template for resume files. for sure you can change it based on your taste :)
To compile it, you just need a c compiler:
  `gcc -lm -o ./output/resume ./examples/resume.c PDFGen/pdfgen.c bisotun.c`
And to run it:
  `./output/resume`

It will generate a pdf file called: `resume.pdf`. now you can open it with any pdf-reader software.

<h1 align="center">
	<img width="900" src="data/resume.png" alt="mpi">
    <br/>
    <h4 align="center">A pdf file generated with bisotun</a></h4>
</h1>

# limitations
- PDFGen currently [doesn't support](arbitrary) using TTF fonts.
- It doesn't support [hyperlinks](https://github.com/AndreRenaud/PDFGen/issues/148).
- PDFGen [doesn't support alpha channels in images](https://github.com/AndreRenaud/PDFGen/issues/149).
