" F4-F11 are available
function! BuildAndOpenThePdf()
  silent execute "!gcc -lm -o ./output/resume ./examples/resume.c PDFGen/pdfgen.c bisotun.c"
  
  let return_status = v:shell_error
  if return_status == 0
    silent execute "!./output/resume"
  else
      echo "Build failed: " . return_status
  endif
endfunction

au BufWrite ./examples/*.c call BuildAndOpenThePdf()
au BufWrite ./examples/*.h call BuildAndOpenThePdf()
au BufWrite *.c call BuildAndOpenThePdf()
au BufWrite *.h call BuildAndOpenThePdf()
