package main

/*
type
  abc=Int64;
var
  x1,y1,x2,y2,x3,y3,x: longint;
  k,r,y : abc;
  input,output: text;
function kol(x,z1,z2:longint):longint;
  var
    min,max,k: longint;
  begin
    if (x<x1)or(x>x2)or(z1>y2)or(z2<y1) then
      k:=0
    else
      begin
        min:=y1;
        if z1>y1 then
          min:=z1;
        max:=y2;
        if z2<y2 then
          max:=z2;
        k:=max-min+1
      end;
     kol:=k
  end;
begin
  assign(input, 'input.txt');
  reset(input);
  assign(output, 'output.txt');
  rewrite(output);
  readln(input,x1,y1,x2,y2);
  read(input,x3,y3,r);
  k:=kol(x3,y3-r,y3+r);
  y:=r;
  for x:=1 to r-1 do
    begin
      while sqr(x)+sqr(y)>sqr(r) do
        y:=y-1;
      k:=k+kol(x3+x,y3-y,y3+y)+kol(x3-x,y3-y,y3+y)
    end;
  k:=k+kol(x3+r,y3,y3)+kol(x3-r,y3,y3);
  write(output,k);
  close(input);
  close(output);
end.
*/

func main() {

}
