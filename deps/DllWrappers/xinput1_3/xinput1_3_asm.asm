.code
  extern dll_procs:QWORD
  f0 proc
  	jmp dll_procs[0 * 8]
  f0 endp
  f1 proc
  	jmp dll_procs[1 * 8]
  f1 endp
  f2 proc
  	jmp dll_procs[2 * 8]
  f2 endp
  f3 proc
  	jmp dll_procs[3 * 8]
  f3 endp
  f4 proc
  	jmp dll_procs[4 * 8]
  f4 endp
  f5 proc
  	jmp dll_procs[5 * 8]
  f5 endp
  f6 proc
  	jmp dll_procs[6 * 8]
  f6 endp
  f7 proc
  	jmp dll_procs[7 * 8]
  f7 endp
  f8 proc
  	jmp dll_procs[8 * 8]
  f8 endp
  f9 proc
  	jmp dll_procs[9 * 8]
  f9 endp
  f10 proc
  	jmp dll_procs[10 * 8]
  f10 endp
  f11 proc
  	jmp dll_procs[11 * 8]
  f11 endp
end