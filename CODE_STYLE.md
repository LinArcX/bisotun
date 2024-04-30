# enums
- should be typedefed.
- the enum name is camelCase.
- the typedef name should be PascalCase.
- items of enums are all UPPER_CASE separated with _.(if necessary)

# structs
- should be typedefed.
- the struct name is camelCase.
- the typedef name should be PascalCase.
- items of structs are all camelCase

# functions
- names are camelCase.
- arguments are camelCase.
- output of function should be write in a line upper than the function prototype.
- the open curley braces should be open a line after function prototype.
  int
  openBisotun(BstnProperties *prop)
  {
    // body
  }

# loops / conditions
- all curley braces should be reside on it's own line
  if(true)
  {
    for(size_t i = 0; i < 42; i++)
    {
      // logic
    }
  }
