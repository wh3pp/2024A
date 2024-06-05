<!DOCTYPE html>
<html lang="es">
  <head>
    <meta charset="UTF-8">
    <link rel="stylesheet" href="styles.css">
    <title>Formulario</title>
  </head>
  <body>
    <div class="contenedor">
      <h2>Formulario: Roni Montañez</h2>
      <form action="bienvenida.php" method="post">
        <div class="relleno">
          <div class="inp">
            <div class="col_50">
              <input class="campos" id="nombre" name="nombre" type="text" placeholder="Nombre..."> 
            </div>
            <div class="col_50">
              <input class="campos" id="apellido" name="apellido" type="text" placeholder="Apellido..."> 
            </div>
          </div>
          <div class="inp">
            <div class="col_50">
              <input class="campos" id="color" name="color" type="text" placeholder="Color Favorito...">
            </div>
            <div class="col_50">
              <input class="campos" id="animal" name="animal" type="text" placeholder="Animal Favorito...">
            </div>
          </div>
          <button id="brnAgregar" class="btn" type="submit">Enviar</button>
        </div>
      </form>
    </div>
  </body>
</html>
