#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[200];
    int estado;
}eMovie;

int main()
{
    char seguir='s';
    int opcion=0;
    int totalVectorPeliculas=1;
    int contadorPeliculas=0;
    int i;
    char AUXtituloPelicula[50];

    FILE* archivoPWeb;

    eMovie unaPelicula;
    FILE* archivoPeliculas;
    archivoPeliculas=fopen("Peliculas.dat", "rb");

    eMovie* vectorPelicula=(eMovie*)malloc(sizeof(eMovie)*totalVectorPeliculas);
    eMovie* AUXvectorPelicula;
    if(archivoPeliculas!=NULL)
    {
        //primer parametro: donde van las peliculas, el sizeof de la estructura, cantidad de elementos de ese tamaño, nombre archivo
        while(fread((void*)(vectorPelicula+contadorPeliculas),sizeof(eMovie), 1, archivoPeliculas)==1)
        {
            contadorPeliculas++;
            totalVectorPeliculas++;

            AUXvectorPelicula=(eMovie*)realloc(vectorPelicula,sizeof(eMovie)*totalVectorPeliculas);
            if(AUXvectorPelicula!=NULL)
            {
                vectorPelicula=AUXvectorPelicula;
            }
        }
        fclose(archivoPeliculas);
    }

    /*for(i=0;i<contadorPeliculas;i++)
    {
        printf("%s\n", vectorPelicula[i].titulo);

    }*/


    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Modificar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1://ALTA DE PELICULA

                unaPelicula.estado=1;
                printf("Ingrese el titulo de la pelicula\n ");
                fflush(stdin);
                gets(unaPelicula.titulo);
                printf("Ingrese el genero de la pelicula:\n ");
                fflush(stdin);
                gets(unaPelicula.genero);
                printf("Ingrese la duracion:\n ");
                fflush(stdin);
                scanf("%d", &unaPelicula.duracion);
                printf("Ingrese la descripcion de la pelicula:\n ");
                fflush(stdin);
                gets(unaPelicula.descripcion);
                printf("Ingrese el puntaje:\n ");
                fflush(stdin);
                scanf("%d", &unaPelicula.puntaje);
                printf("Ingrese el link de la imagen de portada de la pelicula:\n ");
                fflush(stdin);
                gets(unaPelicula.linkImagen);
                AUXvectorPelicula=(eMovie*)realloc(vectorPelicula,sizeof(eMovie)*totalVectorPeliculas);
                if(AUXvectorPelicula!=NULL)
                {
                    vectorPelicula=AUXvectorPelicula;
                }
                vectorPelicula[contadorPeliculas]=unaPelicula;
                contadorPeliculas++;
                totalVectorPeliculas++;
                break;

            case 2://MODIFICACION DE PELICULA

                printf("Ingrese el titulo de la pelicula a modificar\n");
                fflush(stdin);
                gets(AUXtituloPelicula);
                for(i=0;i<contadorPeliculas;i++)
                {
                    if(stricmp(AUXtituloPelicula,vectorPelicula[i].titulo)==0)
                    {
                        printf("INGRESE NUEVOS DATOS\n\n");

                        printf("Ingrese el titulo de la pelicula\n ");
                        fflush(stdin);
                        gets(vectorPelicula[i].titulo);
                        printf("Ingrese el genero de la pelicula:\n ");
                        fflush(stdin);
                        gets(vectorPelicula[i].genero);
                        printf("Ingrese la duracion:\n ");
                        fflush(stdin);
                        scanf("%d", &vectorPelicula[i].duracion);
                        printf("Ingrese la descripcion de la pelicula:\n ");
                        fflush(stdin);
                        gets(vectorPelicula[i].descripcion);
                        printf("Ingrese el puntaje:\n ");
                        fflush(stdin);
                        scanf("%d", &vectorPelicula[i].puntaje);
                        printf("Ingrese el link de la imagen de portada de la pelicula:\n ");
                        fflush(stdin);
                        gets(vectorPelicula[i].linkImagen);
                        break;
                    }
                }
                break;

            case 3://BAJA DE PELICULA
                printf("Ingrese el titulo de la pelicula a dar de baja\n");
                fflush(stdin);
                gets(AUXtituloPelicula);
                for(i=0;i<contadorPeliculas;i++)
                {
                    if(stricmp(AUXtituloPelicula,vectorPelicula[i].titulo)==0)
                    {
                        vectorPelicula[i].estado=0;
                        break;
                    }
                }

               break;

            case 4://CREA PAG WEB

                archivoPWeb=fopen("index.html", "w+");

                fprintf(archivoPWeb, "%s","<html lang='en'>\n");
                fprintf(archivoPWeb, "%s","<head>\n");
                fprintf(archivoPWeb, "%s","    <meta charset='utf-8'>\n");
                fprintf(archivoPWeb, "%s","    <meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
                fprintf(archivoPWeb, "%s","    <meta name='viewport' content='width=device-width, initial-scale=1'>\n");
                fprintf(archivoPWeb, "%s","    <title>Lista peliculas</title>\n");
                fprintf(archivoPWeb, "%s","    <link href='css/bootstrap.min.css' rel='stylesheet'>\n");
                fprintf(archivoPWeb, "%s","    <link href='css/custom.css' rel='stylesheet'>\n");
                fprintf(archivoPWeb, "%s","    </head>\n");
                fprintf(archivoPWeb, "%s","<body>\n");
                fprintf(archivoPWeb, "%s","    <div class='container'>\n");

                //GENERAR PAGINA: COMIENZA
                for(i=0;i<contadorPeliculas;i++)
                {
                    if(vectorPelicula[i].estado==1)
                    {
                        fprintf(archivoPWeb, "%s","			<div class='row'>\n\n\n");
                        fprintf(archivoPWeb, "%s","			<article class='col-md-4 article-intro'>\n");
                        fprintf(archivoPWeb, "%s","                <a href='#'>\n");
                        fprintf(archivoPWeb, "%s","                    <img class='img-responsive img-rounded' src='");
                        fprintf(archivoPWeb, "%s",vectorPelicula[i].linkImagen);
                        fprintf(archivoPWeb, "%s","' alt=''>\n");
                        fprintf(archivoPWeb, "%s","                </a>\n");
                        fprintf(archivoPWeb, "%s","                <h3>\n");
                        fprintf(archivoPWeb, "%s","                    <a href='#'>");
                        fprintf(archivoPWeb, "%s", vectorPelicula[i].titulo);
                        fprintf(archivoPWeb, "%s","</a>\n");
                        fprintf(archivoPWeb, "%s","                </h3>\n");
                        fprintf(archivoPWeb, "%s","				<ul>\n");
                        fprintf(archivoPWeb, "%s","					<li>");
                        fprintf(archivoPWeb, "%s","Genero: ");
                        fprintf(archivoPWeb, "%s", vectorPelicula[i].genero);
                        fprintf(archivoPWeb, "%s","</li>\n");
                        fprintf(archivoPWeb, "%s","					<li>");
                        fprintf(archivoPWeb, "%s","Puntaje: ");
                        fprintf(archivoPWeb, "%d", vectorPelicula[i].puntaje);
                        fprintf(archivoPWeb, "%s","</li>\n");
                        fprintf(archivoPWeb, "%s","					<li>");
                        fprintf(archivoPWeb, "%s","Duracion: ");
                        fprintf(archivoPWeb, "%d", vectorPelicula[i].duracion);
                        fprintf(archivoPWeb, "%s","</li>\n");
                        fprintf(archivoPWeb, "%s","				</ul>\n");
                        fprintf(archivoPWeb, "%s","                <p>");
                        fprintf(archivoPWeb, "%s", vectorPelicula[i].descripcion);
                        fprintf(archivoPWeb, "%s","</p>\n");
                        fprintf(archivoPWeb, "%s","            </article>\n");
                        fprintf(archivoPWeb, "%s","        </div>\n");
                        fprintf(archivoPWeb, "%s","        <!-- /.row -->\n");
                    }
                }
                //GENERAR PAGINA: TERMINA

                fprintf(archivoPWeb, "%s","		</div>\n");
                fprintf(archivoPWeb, "%s","    <!-- /.container -->\n");
                fprintf(archivoPWeb, "%s","    <!-- jQuery -->\n");
                fprintf(archivoPWeb, "%s","    <script src='js/jquery-1.11.3.min.js'></script>\n");
                fprintf(archivoPWeb, "%s","    <!-- Bootstrap Core JavaScript -->\n");
                fprintf(archivoPWeb, "%s","    <script src='js/bootstrap.min.js'></script>\n");
                fprintf(archivoPWeb, "%s","	<!-- IE10 viewport bug workaround -->\n");
                fprintf(archivoPWeb, "%s","	<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
                fprintf(archivoPWeb, "%s","	<!-- Placeholder Images -->\n");
                fprintf(archivoPWeb, "%s","	<script src='js/holder.min.js'></script>\n");
                fprintf(archivoPWeb, "%s","</body>\n");
                fprintf(archivoPWeb, "%s","</html>\n");

                fclose(archivoPWeb);
                printf("LA PAGINA WEB SE HA CREADO\n");
                break;

            case 5:

                archivoPeliculas=fopen("Peliculas.dat", "wb");
                if(archivoPeliculas==NULL)
                {
                    exit(1);
                }
                for(i=0;i<contadorPeliculas;i++)
                {
                    if(vectorPelicula[i].estado==1)
                    {
                        fwrite((vectorPelicula+i), sizeof(eMovie),1, archivoPeliculas);
                    }
                }
                fclose(archivoPeliculas);

                seguir = 'n';
                break;
        }
    }

    return 0;
}
