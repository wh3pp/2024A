<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>Tabla de 100 números primos</title>
    <link rel="stylesheet" href="styles.css">
  </head>
  <body>
    <section id="seccion">
      <h2>Roni Ezequiel Montañez Pacco</h2>
      <h1>Los 100 primeros números primos</h1>
      <%!
        public boolean esPrimo(int num) {
          if (num == 0 || num == 1) {
            return false;
          }
          for (int i=2; i<num/2+1; i++) {
            if(num%i==0){
              return false;
            }
          }
          return true;
        }
      %>
      <table class="tabla">
        <tbody>
          <%
            int count = 0;
            int num = 2;
            out.println("<tr>");
            while (count < 100) {
              if (esPrimo(num)) {
                out.println("<td>" + num + "</td>");
                count++;
                if (count % 10 == 0 && count < 100) {
                  out.println("</tr><tr>");
                }
              }
              num++;
            }
            out.println("</tr>");
          %>
        </tbody>
      </table>
    </section>
  </body>
</html>

