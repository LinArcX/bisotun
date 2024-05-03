#include <string.h>
#include "../bisotun.h"

#define LINE_WIDTH 500
#define LINE_HEIGHT 0.95

#define H0 20
#define H1 18
#define H2 16
#define H3 14
#define PARAGRAPH 13

#define DOT_SIZE 40
#define DASH_SIZE 24
#define H1_SPACES -10
#define LINE_SPACES -20
#define SPACE_PARAGRAPH -20
#define SPACE_SECTION -35

void
contactInformation()
{
  genText(0, 0, 0, H1_SPACES, true, H1, true, false, "Contact Information"); 
  genLine(0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  genIcon(0, -3, -3, 0, true, H1, "./data/person.png");
  genText(25, 0, 0, 0, false, PARAGRAPH, false, false, "Sepehr Mirzakhani"); 

  genIcon(250, -3, 0, 0, true, H2, "./data/mail.png");
  genText(275, 1, 0, SPACE_PARAGRAPH, false, PARAGRAPH, false, false, "sepehr.mirzakhani@venus.com"); 

  genIcon(250, -3, 0, 0, true, H2, "./data/phone.png");
  genText(275, 1, 0, SPACE_PARAGRAPH, false, PARAGRAPH, false, false, "(01) 101-1010"); 

  genIcon(2, 15, -3, 0, false, H2, "./data/home.png");
  genText(25, 18, 0, SPACE_PARAGRAPH, false, PARAGRAPH, false, false, "Venus, Solar system"); 

  genIcon(0, 10, -3, 0, false, H0, "./data/linkedin.png");
  genText(25, 16, 0, SPACE_SECTION + 20, false, PARAGRAPH, false, false, "linkedin.com/in/sepehr-mirzakhani"); 
}

void
education()
{
  genText(0, 0, 0, H1_SPACES, true, H1, true, false, "Education"); 
  genLine(0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  // universit
  genText(0, 2, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(0, 0, 13, 0, false, H2, true, false, "Phobos university, Mars"); 
  genText(250, 0, 13, SPACE_PARAGRAPH, false, PARAGRAPH, false, false, "(October 2044 - September 2048)"); 
  genText(20, 0, 13, 0, false, PARAGRAPH, true, false, "Major:"); 
  genText(70, 0, 13, -18, false, PARAGRAPH, false, false, "Software engineering  (full scholarship)"); 
  genText(20, 0, 13, 0, false, PARAGRAPH, true, false, "GPA:"); 
  genText(70, 0, 13, SPACE_SECTION, false, PARAGRAPH, false, false, "1.8"); 

  // high-scho
  genText(0, 2, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(0, 0, 13, 0, false, H2, true, false, "Triton high-school, Neptune"); 
  genText(250, 0, 13, SPACE_PARAGRAPH, false, PARAGRAPH, false, false, "(2043)"); 
  genText(20, 0, 13, 0, false, PARAGRAPH, true, false, "Major:"); 
  genText(70, 0, 13, -18, false, PARAGRAPH, false, false, "Diploma in Mathematics"); 
  genText(20, 0, 13, 0, false, PARAGRAPH, true, false, "GPA:"); 
  genText(70, 0, 13, SPACE_SECTION, false, PARAGRAPH, false, false, "1.2"); 
}

void
languageSkills()
{
  genText(0, 0, 0, H1_SPACES, true, H1, true, false, "Language Skills"); 
  genLine(0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  genText(0, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(0, 0, 13, 0, false, H3, true, false, "English:"); 
  genText(70, 0, 30, 0, false, PARAGRAPH, false, false, "IELTS 8"); 
 
  genText(160, 3, 13, 0, false, DOT_SIZE, false, false, "."); 
  genText(175, 0, 13, 0, false, H3, true, false, "Persian:"); 
  genText(230, 0, 13, 0, false, PARAGRAPH, false, false, "Native"); 

  genText(310, 3, 13, 0, false, DOT_SIZE, false, false, "."); 
  genText(325, 0, 13, 0, false, H3, true, false, "French:"); 
  genText(380, 0, 13, SPACE_SECTION, false, PARAGRAPH, false, false, "Elementary"); 
}

void
researchInterests()
{
  genText(0, 0, 0, H1_SPACES, true, H1, true, false, "Research interests"); 
  genLine(0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  genText(0, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(0, 0, 30, 0, false, PARAGRAPH, false, false, "Operating system development"); 
  genText(260, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(263, 0, 30, SPACE_SECTION, false, PARAGRAPH, false, false, "Progamming languages"); 
}

void
honorsAndAwards()
{
  genText(0, 0, 0, H1_SPACES, true, H1, true, false, "Honors and awards"); 
  genLine(0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  genText(0, -1, 13, 0, true, DASH_SIZE, false, false, "-"); 
  genText(0, 0, 30, SPACE_SECTION, false, PARAGRAPH, false, false, "Ranked 42 among 42777 participants in the nationwide enterance exam [2043]"); 
}

void
trainingCoursesAndCertifications()
{
  genText(0, 0, 0, H1_SPACES, true, H1, true, false, "Training courses and certifications"); 
  genLine(0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  genText(0, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(0, 0, 13, LINE_SPACES, false, H2, true, false, "Less is more"); 
 
  genText(20, 0, 13, 0, true, H3, true, false, "By:"); 
  genText(30, 0, 13, 0, false, PARAGRAPH, false, false, "His father"); 

  genText(345, 0, 13, 0, false, H3, true, false, "Issued:"); 
  genText(390, 0, 13, SPACE_SECTION, false, PARAGRAPH, false, false, "2030"); 

  genText(0, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(0, 0, 13, LINE_SPACES, false, H2, true, false, "How to love yourself?"); 
 
  genText(20, 0, 13, 0, true, H3, true, false, "By:"); 
  genText(30, 0, 13, 0, false, PARAGRAPH, false, false, "Her mother"); 

  genText(345, 0, 13, 0, false, H3, true, false, "Issued:"); 
  genText(390, 0, 13, SPACE_SECTION, false, PARAGRAPH, false, false, "2029"); 
}

void
personalSkills()
{
  genText(0, 0, 0, H1_SPACES, true, H1, true, false, "Personal skills"); 
  genLine(0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  genText(0, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(0, 0, 13, LINE_SPACES, false, H2, true, false, "Soft skills"); 
  genText(20, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(20, 0, 30, 0, false, PARAGRAPH, false, false, "Careless"); 
  genText(140, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(140, 0, 30, 0, false, PARAGRAPH, false, false, "Smilling"); genText(250, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(250, 0, 30, 0, false, PARAGRAPH, false, false, "Happy"); 
  genText(360, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(360, 0, 30, LINE_SPACES, false, PARAGRAPH, false, false, "Easygoing"); 

  genText(0, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(0, 0, 10, LINE_SPACES, false, H2, true, false, "Hard skills"); 
  genText(20, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(20, 0, 30, 0, false, PARAGRAPH, false, false, "Assembly"); 
  genText(100, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(100, 0, 30, 0, false, PARAGRAPH, false, false, "c"); 
  genText(140, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(140, 0, 30, 0, false, PARAGRAPH, false, false, "sepehr-lang"); 
  genText(230, -1, 10, 0, true, DASH_SIZE, false, false, "-"); 
  genText(230, 0, 30, SPACE_PARAGRAPH, false, PARAGRAPH, false, false, "zaal os"); 
}

void
hobbies()
{
  genText(0, 0, 0, H1_SPACES, true, H1, true, false, "Hobbies"); 
  genLine(0, 0, 0, LINE_SPACES, true, LINE_WIDTH, LINE_HEIGHT);

  genText(0, 3, 13, 0, true, DOT_SIZE, false, false, "."); 
  genText(0, 0, 13, 0, false, H3, true, false, "programming"); 
 
  genText(160, 3, 13, 0, false, DOT_SIZE, false, false, "."); 
  genText(175, 0, 13, 0, false, H3, true, false, "literature"); 
}
 
int
main(int argc, char *argv[])
{
  BstnProperties prop;
  prop.margin.top = 35;
  prop.margin.bottom = prop.margin.top;
  prop.margin.left = 30;
  prop.margin.right = prop.margin.left;
  prop.pageSize = A4;
  prop.pageNumber.position = BOTTOM_CENTER;
  prop.pageNumber.autoGenerate = true;
  prop.pageNumber.fontSize = 12;
  prop.pageNumber.currentNumber = 1;

  // Supported fonts by PDFGen:
  //   Courier, Courier-Bold, Courier-BoldOblique, Courier-Oblique,
  //   Helvetica, Helvetica-Bold, Helvetica-BoldOblique, Helvetica-Oblique,
  //   Times-Roman, Times-Bold, Times-Italic, Times-BoldItalic, Symbol or ZapfDingbats
  char* fontRegular = "Times-Roman";
  strncpy(prop.font.regular.name, fontRegular, strnlen(fontRegular, ARRAY_SIZE - 1)); 
 
  char* fontBold = "Times-Bold";
  strncpy(prop.font.bold.name, fontBold, strnlen(fontBold, ARRAY_SIZE - 1)); 

  char* fontItalic = "Times-Italic";
  strncpy(prop.font.italic.name, fontItalic, strnlen(fontItalic, ARRAY_SIZE - 1)); 

  char* title = "resume.pdf";
  strncpy(prop.title, title, strnlen(title, ARRAY_SIZE - 1)); 
  char* author = "sepehr";
  strncpy(prop.author, author, strnlen(author, ARRAY_SIZE - 1)); 
  char* subject = "resume";
  strncpy(prop.author, subject, strnlen(subject, ARRAY_SIZE - 1)); 

  if(openBisotun(&prop))
  {
    genPage();
    {
      contactInformation();
      education();
      languageSkills();
      researchInterests();
      honorsAndAwards();
      personalSkills();
      hobbies();
    }
    genPage();
    {
      trainingCoursesAndCertifications();
    }

    saveBisotun();
  }
  closeBisotun();
  return 0;
}
