#include "Models.h"


/* Lion */
void DrawAnimal1(){

  /* circle */
  static int animal1Index;
        //small sphere arbitrary center
        CurrentMesh = 62; 
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          //ModelTrans.rotate( cos(Accumulator) * (5.0), vec3(1, 0, 0));
         
          ModelTrans.translate(vec3(5, 1, 0));
          ModelTrans.rotate( -90, vec3(0, 1, 0));
            if(flag == 0){
              animal1Index = centers.size();
              centers.push_back(ModelTrans.getMatrix()*vec4(0, 0, 0, 1));
          }
          SetModel();
          safe_glEnableVertexAttribArray(h_aPosition);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
          safe_glEnableVertexAttribArray(h_aNormal);
          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
          safe_glUniform1f(h_uMaterial, 0.5);
          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);

          
                /* head */
                  CurrentMesh = 64; 
                  safe_glEnableVertexAttribArray(h_aPosition);
                  safe_glEnableVertexAttribArray(h_aNormal); 
                    ModelTrans.pushMatrix();

                    SetModel();
                    safe_glEnableVertexAttribArray(h_aPosition);
                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    safe_glEnableVertexAttribArray(h_aNormal);
                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                    glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                    safe_glUniform1f(h_uMaterial, 0.5);
                    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                    ModelTrans.popMatrix();
                          /* white head */
                            CurrentMesh = 65; 
                            safe_glEnableVertexAttribArray(h_aPosition);
                            safe_glEnableVertexAttribArray(h_aNormal); 
                              ModelTrans.pushMatrix();
                              ModelTrans.translate(vec3(0, 0, 0.5));
                              SetModel();
                              safe_glEnableVertexAttribArray(h_aPosition);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                              safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                              safe_glEnableVertexAttribArray(h_aNormal);
                              glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                              safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                              glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                               glUniform3f(h_uColor, changeColor[animal1Index].x, changeColor[animal1Index].y, changeColor[animal1Index].z);
                              safe_glUniform1f(h_uMaterial, 0.5);
                              glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                              ModelTrans.popMatrix();
              

                  /* multiple spheres */
                for(int s = 1; s < 4; s++){
                  CurrentMesh = 30; 
                  safe_glEnableVertexAttribArray(h_aPosition);
                  safe_glEnableVertexAttribArray(h_aNormal); 
                    ModelTrans.pushMatrix();
                    
                    if(s == 1){
                      ModelTrans.rotate( 90, vec3(0, 0, 1));
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }else if(s == 2){
                      ModelTrans.rotate( 180, vec3(0, 0, 1));
                      ModelTrans.translate(vec3(-0.1, -.5, 1.5));
                    }else if(s == 3){
                      ModelTrans.rotate( 270, vec3(0, 0, 1));
                      ModelTrans.translate(vec3(-0.1, 0, 0));
                    }else if(s == 4){
                      
                    }
                    SetModel();
                    safe_glEnableVertexAttribArray(h_aPosition);
                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    safe_glEnableVertexAttribArray(h_aNormal);
                    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                    glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                    safe_glUniform1f(h_uMaterial, 0.5);
                    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                    ModelTrans.popMatrix();
                }

                      /* petal ellipse */
                      for(int g = 1; g<14; g++){
                          CurrentMesh = 25;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                          
                          if(g == 1){
                            ModelTrans.translate(vec3(-.5, 0, 0));
                          }else if (g ==2){
                            ModelTrans.rotate(30, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==3){
                            ModelTrans.rotate(60, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==4){
                            ModelTrans.rotate(90, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==5){
                            ModelTrans.rotate(120, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==6){
                            ModelTrans.rotate(150, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==7){
                            ModelTrans.rotate(180, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==8){
                            ModelTrans.rotate(210, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==9){
                            ModelTrans.rotate(230, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==10){
                            ModelTrans.rotate(260, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==11){
                            ModelTrans.rotate(290, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==12){
                            ModelTrans.rotate(320, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }else if (g ==13){
                            ModelTrans.rotate(340, vec3(0, 0, 1));
                            ModelTrans.translate(vec3(-0.5, 0, 0));
                          }
                          ModelTrans.rotate(90, vec3(0, 0, 1));
                          SetModel();
                          safe_glEnableVertexAttribArray(h_aPosition);
                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                          safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                          glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                          safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                          glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                          glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                          safe_glUniform1f(h_uMaterial, 0.5);
                          glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                          ModelTrans.popMatrix();
                      }
                              /* white petal ellipse */
                              for(int g = 1; g<14; g++){
                                  CurrentMesh = 26;
                                  safe_glEnableVertexAttribArray(h_aPosition);
                                  safe_glEnableVertexAttribArray(h_aNormal); 
                                  ModelTrans.pushMatrix();
                                  
                                  if(g == 1){
                                    ModelTrans.translate(vec3(-.5, 0, 0.1));
                                  }else if (g ==2){
                                    ModelTrans.rotate(30, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==3){
                                    ModelTrans.rotate(60, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==4){
                                    ModelTrans.rotate(90, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==5){
                                    ModelTrans.rotate(120, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==6){
                                    ModelTrans.rotate(150, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==7){
                                    ModelTrans.rotate(180, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==8){
                                    ModelTrans.rotate(210, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==9){
                                    ModelTrans.rotate(230, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==10){
                                    ModelTrans.rotate(260, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==11){
                                    ModelTrans.rotate(290, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==12){
                                    ModelTrans.rotate(320, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }else if (g ==13){
                                    ModelTrans.rotate(340, vec3(0, 0, 1));
                                    ModelTrans.translate(vec3(-0.5, 0, 0.1));
                                  }
                                  ModelTrans.rotate(90, vec3(0, 0, 1));
                                  SetModel();
                                  safe_glEnableVertexAttribArray(h_aPosition);
                                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                  safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                    safe_glEnableVertexAttribArray(h_aNormal);
                                  glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                  safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                  glUniform3f(h_uColor, changeColor[animal1Index ].x, changeColor[animal1Index ].y, changeColor[animal1Index ].z);
                                  safe_glUniform1f(h_uMaterial, 0.5);
                                  glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                  ModelTrans.popMatrix();
                              }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
}