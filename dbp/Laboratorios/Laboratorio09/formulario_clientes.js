const isEmpty = (str) => str.trim() === '';
function agregar(){
  var dni = document.getElementById('dni');
  var nombres = document.getElementById('nombres');
  var apellidop = document.getElementById('apellidop');
  var apellidom = document.getElementById('apellidom');
  var color = document.querySelector('input[name="color"]:checked');
  dniVal = dni.value;
  nombresVal = nombres.value;
  apellidopVal = apellidop.value;
  apellidomVal = apellidom.value;
  colorVal = color ? color.value : '';

  tablaUsuarios = document.getElementById('tablaUsuarios');
  if(isEmpty(dniVal) || isEmpty(nombresVal) || isEmpty(apellidopVal) || isEmpty(apellidomVal) || isEmpty(colorVal)){
    alert('Todos los campos son obligatorios');
    return;
  }
  var contenido = document.getElementById("contenido");
  if(window.XMLHttpRequest) {
    ajax = new XMLHttpRequest();
  }else{
    ajax = new ActiveXObject("Microsoft.XMLHTTP");
  }
  ajax.onreadystatechange = function(){
    if(ajax.readyState == 4 && ajax.status == 200){
      contenido.innerHTML = ajax.responseText;
    } else{
      contenido.innerHTML = "<img width='50' height='50' src='cargando.gif'>";
    }
  }
  ajax.open("POST","mostrar_ajax.jsp");
  ajax.setRequestHeader("Content-Type","application/x-www-form-urlencoded");
  ajax.send("dni=" + dniVal + "&nombres=" + nombresVal + "&apellidop=" + apellidopVal + "&apellidom=" + apellidomVal + "&color=" + colorVal);
}

function asignar(){
  btnAgregar = document.getElementById("btnAgregar");
  btnAgregar.addEventListener("click",agregar);
}
window.addEventListener("load",asignar);
