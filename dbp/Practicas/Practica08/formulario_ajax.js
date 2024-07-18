const isEmpty = (str) => str.trim() === '';
function agregar(){
  var dni = document.getElementById('dni');
  var nombre = document.getElementById('nombre');
  var apellidop = document.getElementById('apellidop');
  var apellidom = document.getElementById('apellidom');
  var color = document.getElementById('color');
  var desayuno = document.getElementById('desayuno');
  var auto = document.getElementById('auto');
  var limpieza = document.getElementById('limpieza');
  dniVal = dni.value;
  nombreVal = nombre.value;
  apellidopVal = apellidop.value;
  apellidomVal = apellidom.value;
  colorVal = color.value;
  desayunoVal = desayuno.checked ? 1 : 0; 
  autoVal = auto.checked ? 1 : 0;
  limpiezaVal = limpieza.checked ? 1 : 0;

  tablaUsuarios = document.getElementById('tablaUsuarios');
  if(isEmpty(dniVal) || isEmpty(nombreVal) || isEmpty(apellidopVal) || isEmpty(apellidomVal) || isEmpty(colorVal)) {
    alert('Todos los campos son obligatorios');
    return;
  }
  var contenido = document.getElementById('contenido');
  if(window.XMLHttpRequest) {
    ajax = new XMLHttpRequest();
  } else {
    ajax = new ActiveXObject("Microsoft.XMLHTTP");
  }
  ajax.onreadystatechange = function(){
    if(ajax.readyState == 4 && ajax.status == 200){
      contenido.innerHTML = ajax.responseText;
    } else{
      contenido.innerHTML = "<img width='50' height='50' src='cargando.gif'>";
    }
  }
  ajax.open("POST","mostrar_ajax.php");
  ajax.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
  ajax.send("dni=" + dniVal + "&nombres=" + nombreVal + "&apellidop=" + apellidopVal + "&apellidom=" + apellidomVal + "&color=" + colorVal + "&desayuno=" + desayunoVal + "&auto=" + autoVal + "&limpieza=" + limpiezaVal);
}

function asignar(){
  btnAgregar = document.getElementById("btnAgregar");
  btnAgregar.addEventListener("click",agregar);
}
window.addEventListener("load",asignar);
