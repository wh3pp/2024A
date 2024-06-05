function esNombre(string){
  if(string == ""){
    return false;
  }
  for(var i=0; i< string.length; i++){
    let n = string.charCodeAt(i);
    if((n >=97 && n<=122) || (n>=65 && n<=90) || n==32 ){
      continue;
    }else{
      return false;
    }
  }
  return true;
}

function esMail(string){
  if(string==""){
    return false;
  }
  var c=0;
  for(var i=0; i< string.length; i++){
    if(string[i]=='@'){
      c++;
    }
    if(string[i]==" "){
      return false;
    }
  }
  if(c==1){
    return true;
  }else{
    return false;
  }
}

function esNumeroDePeru(string){
  if(string[0]!='9' || string.length != 9 || string == ""){
    return false;
  }
  for(var i=1; i< string.length; i++){
    let n = string.charCodeAt(i);
    if(n<48 || n>57){
      return false;
    }
  }
  return true;
}


function check_name(){
  nombre = document.getElementById("nombre").value;
  if(esNombre(nombre)){
    document.getElementById("nombreinfo").value = "Correcto";
  }
  else {
    document.getElementById("nombreinfo").value = "Incorrecto";
  }
}

function check_mail(){
  mail = document.getElementById("mail").value;
  if(esMail(mail)){
    document.getElementById("mailinfo").value = "Correcto";
  }else{
    document.getElementById("mailinfo").value = "Incorrecto";
  }
}

function check_phone(){
  phone = document.getElementById("telefono").value;
  if(esNumeroDePeru(phone)){
    document.getElementById("telinfo").value = "Correcto";
  }else{
    document.getElementById("telinfo").value = "Incorrecto";
  }
}

