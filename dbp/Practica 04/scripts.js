function calcular() {
  var n = parseInt(document.getElementById("numero").value);
  var t = document.getElementById("tablaNumeros");
  var Fila = "<tr>";

  for (var i = 1; i <= 20; i++) {
    Fila += "<td>" + n * i + "</td>";
  }

  Fila += "</tr>";
  t.lastElementChild.insertAdjacentHTML("beforeend", Fila);
}

function insertarColumnas(){
  for(var i=2; i<=20; i++){
    document.write("<th>x"+i+"</th>");
  }
}
