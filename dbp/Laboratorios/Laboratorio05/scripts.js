function insertar() {
  var n = parseInt(document.getElementById("numero").value);
  var t = document.getElementById("tablaNumeros");
  var Fila="";
  for (var i = 1; i <= 10; i++) {
    Fila += "<td>" + n * i + "</td>";
  }
  t.lastElementChild.insertAdjacentHTML("beforeend", "<tr>" + Fila + "</tr");
}

function eliminar() {
  var a = document.getElementById("tablaNumeros");
  var t = a.getElementsByTagName("tbody")[0];
  var fil = t.getElementsByTagName("tr");
  if(fil.length > 0){
    fil[fil.length-1].remove();
  }else{
    alert("La tabla no tiene filas");
  }
}

function insertarColumnas(){
  for(var i=2; i<=10; i++){
    document.write("<th>x"+i+"</th>");
  }
}
