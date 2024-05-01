# bisotun
A simple & minimal wrapper library around [PDFGen](https://github.com/AndreRenaud/PDFGen) to generate resume/books/documents more easily.

# why?
I need to generate PDF files, mostly to write my resume. There are some options avilable:
1. Microsoft Word: write your doc and export a pdf file.
2. Typesetting systems like Tex/Latex, groff/troff/nroff, etc..
3. Online websites.

I tested all of the them, but none of them was my favorite. The values that i appreciate:
- having a tool to allows me generate a PDF file in a simpleset/minimal manner.
- having 100% control over my tool.
  - maybe typesettings systems like Tex/Latex have this property because you think it's free and open-source, right? Let's face it: have a good time to fully understand it!
  - i don't want to talk about online website. You don't even know what's happening behind the scene :) 
- Tex/Latex is huge. there are some stripped versions of it. but damn.. it's still a lot for just generating a PDF document.
  - And it's not only about the size on your disk. It has a package manager with lots of dependencies. come on! i want to generate just a pdf.
  - i don't care about different file format that we can generate in Tex/Latex. Just generating PDF files are important for me.

# structure of the repo
To use __bisotun__, you can just add it as a git submodule to your current project like this:

```
git submodule add https://github.com/LinArcX/bisotun
git submodule update --init --recursive
```

or if you want to do the old way, just copy:
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
