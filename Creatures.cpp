#include "Models.h"


/* Little ones for the forest! */
void DrawCreature1(){

  /* circle */
  static int creature1Index;
    CurrentMesh = 58;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();

            ModelTrans.rotate( cos(Accumulator) * (-20.0), vec3(1, 0, 0));
            ModelTrans.translate(vec3(28, 3, 0));

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

              //white face sphere 
              CurrentMesh = 59;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 
              ModelTrans.pushMatrix();
                ModelTrans.translate(vec3(-0.05, 0.0, 0));
                if(flag == 0){
                  creature1Index = centers.size();
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
                glUniform3f(h_uColor, changeColor[creature1Index].x, changeColor[creature1Index].y, changeColor[creature1Index].z);
                safe_glUniform1f(h_uMaterial, 1.0);
                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();

                     //decorative spheres & eyes
                      for(int y = 1; y < 4; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.7, 0.1, -0.35));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.7, 0.1, 0.35));
                            }else if( y == 3){
                                ModelTrans.translate(vec3(-0.58, -0.4, 0));
                            }
                            //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }
                                  //face lines
                                  for(int s = 1; s<7; s++){
                                    CurrentMesh = 55;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                      if(s == 1){
                                        ModelTrans.translate(vec3(-0.77, 0.3, 0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if( s == 2){
                                        ModelTrans.translate(vec3(-0.77, 0.3, -0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 3){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 4){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 5){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 6){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }

                                      SetModel();
                                      safe_glEnableVertexAttribArray(h_aPosition);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                      safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                      safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                      safe_glUniform1f(h_uMaterial, 1.0);
                                      glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                      ModelTrans.popMatrix();
                                  }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
}

void DrawCreature2(){

  /* circle */
  static int creature2Index;
    CurrentMesh = 58;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();
          ModelTrans.rotate( cos(Accumulator) * (-10.0), vec3(0, 0, 1));
          ModelTrans.rotate( 100, vec3(0, 1, 0));
          ModelTrans.translate(vec3(20.5, 10, 0));
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

              //white face sphere 
              CurrentMesh = 59;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 
              ModelTrans.pushMatrix();
                ModelTrans.translate(vec3(-0.05, 0.0, 0));
                if(flag == 0){
                  creature2Index = centers.size();
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
                glUniform3f(h_uColor, changeColor[creature2Index].x, changeColor[creature2Index].y, changeColor[creature2Index].z);
                safe_glUniform1f(h_uMaterial, 1.0);
                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();

                     //decorative spheres & eyes
                      for(int y = 1; y < 4; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.7, 0.1, -0.35));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.7, 0.1, 0.35));
                            }else if( y == 3){
                                ModelTrans.translate(vec3(-0.58, -0.4, 0));
                            }
                            //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }
                                  //face lines
                                  for(int s = 1; s<7; s++){
                                    CurrentMesh = 55;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                      if(s == 1){
                                        ModelTrans.translate(vec3(-0.77, 0.3, 0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if( s == 2){
                                        ModelTrans.translate(vec3(-0.77, 0.3, -0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 3){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 4){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 5){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 6){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }

                                      SetModel();
                                      safe_glEnableVertexAttribArray(h_aPosition);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                      safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                      safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                      safe_glUniform1f(h_uMaterial, 1.0);
                                      glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                      ModelTrans.popMatrix();
                                  }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
}


void DrawCreature3(){

  /* circle */
  static int creature3Index;
    CurrentMesh = 58;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();

          ModelTrans.rotate( cos(Accumulator) * (20.0), vec3(1, 0, 0));
          ModelTrans.rotate( 45, vec3(0, 1, 0));
          ModelTrans.translate(vec3(25, 10.5, 0));

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

              //white face sphere 
              CurrentMesh = 59;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 
              ModelTrans.pushMatrix();
                ModelTrans.translate(vec3(-0.05, 0.0, 0));
                if(flag == 0){
                  creature3Index = centers.size();
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
                glUniform3f(h_uColor, changeColor[creature3Index].x, changeColor[creature3Index].y, changeColor[creature3Index].z);
                safe_glUniform1f(h_uMaterial, 1.0);
                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();

                     //decorative spheres & eyes
                      for(int y = 1; y < 4; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.7, 0.1, -0.35));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.7, 0.1, 0.35));
                            }else if( y == 3){
                                ModelTrans.translate(vec3(-0.58, -0.4, 0));
                            }
                            //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }
                                  //face lines
                                  for(int s = 1; s<7; s++){
                                    CurrentMesh = 55;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                      if(s == 1){
                                        ModelTrans.translate(vec3(-0.77, 0.3, 0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if( s == 2){
                                        ModelTrans.translate(vec3(-0.77, 0.3, -0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 3){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 4){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 5){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 6){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }

                                      SetModel();
                                      safe_glEnableVertexAttribArray(h_aPosition);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                      safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                      safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                      safe_glUniform1f(h_uMaterial, 1.0);
                                      glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                      ModelTrans.popMatrix();
                                  }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
}


void DrawCreature4(){

  /* circle */
  static int creature4Index;
    CurrentMesh = 58;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();

        ModelTrans.rotate( cos(Accumulator) * (10.0), vec3(1, 0, 0)); //disappear in tree
        ModelTrans.rotate( 130, vec3(0, 1, 0));
        ModelTrans.translate(vec3(24, 11.4, 0));

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

              //white face sphere 
              CurrentMesh = 59;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 
              ModelTrans.pushMatrix();
                ModelTrans.translate(vec3(-0.05, 0.0, 0));
                if(flag == 0){
                  creature4Index = centers.size();
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
                glUniform3f(h_uColor, changeColor[creature4Index].x, changeColor[creature4Index].y, changeColor[creature4Index].z);
                safe_glUniform1f(h_uMaterial, 1.0);
                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();

                     //decorative spheres & eyes
                      for(int y = 1; y < 4; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.7, 0.1, -0.35));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.7, 0.1, 0.35));
                            }else if( y == 3){
                                ModelTrans.translate(vec3(-0.58, -0.4, 0));
                            }
                            //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }
                                  //face lines
                                  for(int s = 1; s<7; s++){
                                    CurrentMesh = 55;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                      if(s == 1){
                                        ModelTrans.translate(vec3(-0.77, 0.3, 0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if( s == 2){
                                        ModelTrans.translate(vec3(-0.77, 0.3, -0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 3){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 4){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 5){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 6){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }

                                      SetModel();
                                      safe_glEnableVertexAttribArray(h_aPosition);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                      safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                      safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                      safe_glUniform1f(h_uMaterial, 1.0);
                                      glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                      ModelTrans.popMatrix();
                                  }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
}

void DrawCreature5(){

  /* circle */
  static int creature5Index;
    CurrentMesh = 58;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();

        ModelTrans.rotate( cos(Accumulator) * (-10.0), vec3(1, 0, 0));   
        ModelTrans.rotate( 205, vec3(0, 1, 0));
        ModelTrans.translate(vec3(24, 15, 0));

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

              //white face sphere 
              CurrentMesh = 59;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 
              ModelTrans.pushMatrix();
                ModelTrans.translate(vec3(-0.05, 0.0, 0));
                if(flag == 0){
                  creature5Index = centers.size();
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
                glUniform3f(h_uColor, changeColor[creature5Index].x, changeColor[creature5Index].y, changeColor[creature5Index].z);
                safe_glUniform1f(h_uMaterial, 1.0);
                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();

                     //decorative spheres & eyes
                      for(int y = 1; y < 4; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.7, 0.1, -0.35));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.7, 0.1, 0.35));
                            }else if( y == 3){
                                ModelTrans.translate(vec3(-0.58, -0.4, 0));
                            }
                            //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }
                                  //face lines
                                  for(int s = 1; s<7; s++){
                                    CurrentMesh = 55;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                      if(s == 1){
                                        ModelTrans.translate(vec3(-0.77, 0.3, 0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if( s == 2){
                                        ModelTrans.translate(vec3(-0.77, 0.3, -0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 3){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 4){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 5){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 6){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }

                                      SetModel();
                                      safe_glEnableVertexAttribArray(h_aPosition);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                      safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                      safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                      safe_glUniform1f(h_uMaterial, 1.0);
                                      glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                      ModelTrans.popMatrix();
                                  }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
}


void DrawCreature6(){

  /* circle */
  static int creature6Index;
    CurrentMesh = 58;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();

        ModelTrans.rotate( cos(Accumulator) * (-5.0), vec3(1, 0, 0));
        ModelTrans.rotate( -40, vec3(0, 1, 0));
        ModelTrans.translate(vec3(26, 5, 0));

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

              //white face sphere 
              CurrentMesh = 59;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 
              ModelTrans.pushMatrix();
                ModelTrans.translate(vec3(-0.05, 0.0, 0));
                if(flag == 0){
                  creature6Index = centers.size();
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
                glUniform3f(h_uColor, changeColor[creature6Index].x, changeColor[creature6Index].y, changeColor[creature6Index].z);
                safe_glUniform1f(h_uMaterial, 1.0);
                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();

                     //decorative spheres & eyes
                      for(int y = 1; y < 4; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.7, 0.1, -0.35));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.7, 0.1, 0.35));
                            }else if( y == 3){
                                ModelTrans.translate(vec3(-0.58, -0.4, 0));
                            }
                            //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }
                                  //face lines
                                  for(int s = 1; s<7; s++){
                                    CurrentMesh = 55;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                      if(s == 1){
                                        ModelTrans.translate(vec3(-0.77, 0.3, 0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if( s == 2){
                                        ModelTrans.translate(vec3(-0.77, 0.3, -0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 3){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 4){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 5){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 6){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }

                                      SetModel();
                                      safe_glEnableVertexAttribArray(h_aPosition);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                      safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                      safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                      safe_glUniform1f(h_uMaterial, 1.0);
                                      glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                      ModelTrans.popMatrix();
                                  }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
}



void DrawCreature7(){

  /* circle */
  static int creature7Index;
    CurrentMesh = 58;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();

        ModelTrans.rotate( cos(Accumulator) * (5.0), vec3(1, 0, 0));
        ModelTrans.rotate( -60, vec3(0, 1, 0));
        ModelTrans.translate(vec3(26, -2, 0));

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

              //white face sphere 
              CurrentMesh = 59;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 
              ModelTrans.pushMatrix();
                ModelTrans.translate(vec3(-0.05, 0.0, 0));
                if(flag == 0){
                  creature7Index = centers.size();
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
                glUniform3f(h_uColor, changeColor[creature7Index].x, changeColor[creature7Index].y, changeColor[creature7Index].z);
                safe_glUniform1f(h_uMaterial, 1.0);
                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();

                     //decorative spheres & eyes
                      for(int y = 1; y < 4; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.7, 0.1, -0.35));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.7, 0.1, 0.35));
                            }else if( y == 3){
                                ModelTrans.translate(vec3(-0.58, -0.4, 0));
                            }
                            //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }
                                  //face lines
                                  for(int s = 1; s<7; s++){
                                    CurrentMesh = 55;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                      if(s == 1){
                                        ModelTrans.translate(vec3(-0.77, 0.3, 0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if( s == 2){
                                        ModelTrans.translate(vec3(-0.77, 0.3, -0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 3){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 4){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 5){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 6){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }

                                      SetModel();
                                      safe_glEnableVertexAttribArray(h_aPosition);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                      safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                      safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                      safe_glUniform1f(h_uMaterial, 1.0);
                                      glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                      ModelTrans.popMatrix();
                                  }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
}


void DrawCreature8(){

  /* circle */
  static int creature8Index;
    CurrentMesh = 58;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();

        ModelTrans.rotate( cos(Accumulator) * (5.0), vec3(1, 0, 0));
        ModelTrans.rotate( -170, vec3(0, 1, 0));
        ModelTrans.translate(vec3(24.5, 2, 0));

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

              //white face sphere 
              CurrentMesh = 59;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 
              ModelTrans.pushMatrix();
                ModelTrans.translate(vec3(-0.05, 0.0, 0));
                if(flag == 0){
                  creature8Index = centers.size();
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
                glUniform3f(h_uColor, changeColor[creature8Index].x, changeColor[creature8Index].y, changeColor[creature8Index].z);
                safe_glUniform1f(h_uMaterial, 1.0);
                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();

                     //decorative spheres & eyes
                      for(int y = 1; y < 4; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.7, 0.1, -0.35));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.7, 0.1, 0.35));
                            }else if( y == 3){
                                ModelTrans.translate(vec3(-0.58, -0.4, 0));
                            }
                            //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }
                                  //face lines
                                  for(int s = 1; s<7; s++){
                                    CurrentMesh = 55;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                      if(s == 1){
                                        ModelTrans.translate(vec3(-0.77, 0.3, 0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if( s == 2){
                                        ModelTrans.translate(vec3(-0.77, 0.3, -0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 3){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 4){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 5){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 6){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }

                                      SetModel();
                                      safe_glEnableVertexAttribArray(h_aPosition);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                      safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                      safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                      safe_glUniform1f(h_uMaterial, 1.0);
                                      glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                      ModelTrans.popMatrix();
                                  }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
}


void DrawCreature9(){

  /* circle */
  static int creature9Index;
    CurrentMesh = 58;
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();

        ModelTrans.rotate( cos(Accumulator) * (-5.0), vec3(1, 0, 0));
        ModelTrans.rotate( 50, vec3(0, 1, 0));
        ModelTrans.translate(vec3(26, 1.0, 0));

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

              //white face sphere 
              CurrentMesh = 59;
              safe_glEnableVertexAttribArray(h_aPosition);
              safe_glEnableVertexAttribArray(h_aNormal); 
              ModelTrans.pushMatrix();
                ModelTrans.translate(vec3(-0.05, 0.0, 0));
                if(flag == 0){
                  creature9Index = centers.size();
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
                glUniform3f(h_uColor, changeColor[creature9Index].x, changeColor[creature9Index].y, changeColor[creature9Index].z);
                safe_glUniform1f(h_uMaterial, 1.0);
                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                ModelTrans.popMatrix();

                     //decorative spheres & eyes
                      for(int y = 1; y < 4; y++){
                          CurrentMesh = 54;
                          safe_glEnableVertexAttribArray(h_aPosition);
                          safe_glEnableVertexAttribArray(h_aNormal); 
                          ModelTrans.pushMatrix();
                            if(y == 1){
                                ModelTrans.translate(vec3(-0.7, 0.1, -0.35));
                            }else if( y == 2){
                                ModelTrans.translate(vec3(-0.7, 0.1, 0.35));
                            }else if( y == 3){
                                ModelTrans.translate(vec3(-0.58, -0.4, 0));
                            }
                            //ModelTrans.rotate(-90, vec3(0, 1, 0));  
                            SetModel();
                            safe_glEnableVertexAttribArray(h_aPosition);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                            safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            safe_glEnableVertexAttribArray(h_aNormal);
                            glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                            safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                            glUniform3f(h_uColor, 0.0, 0.0, 0.0);
                            safe_glUniform1f(h_uMaterial, 1.0);
                            glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                            ModelTrans.popMatrix();
                      }
                                  //face lines
                                  for(int s = 1; s<7; s++){
                                    CurrentMesh = 55;
                                    safe_glEnableVertexAttribArray(h_aPosition);
                                    safe_glEnableVertexAttribArray(h_aNormal); 
                                    ModelTrans.pushMatrix();
                                      if(s == 1){
                                        ModelTrans.translate(vec3(-0.77, 0.3, 0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if( s == 2){
                                        ModelTrans.translate(vec3(-0.77, 0.3, -0.32));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 3){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 4){
                                        ModelTrans.translate(vec3(-0.8, -0.2, 0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 5){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.4));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }else if(s == 6){
                                        ModelTrans.translate(vec3(-0.8, -0.2, -0.3));
                                        ModelTrans.rotate(-90, vec3(1, 0, 0));
                                      }

                                      SetModel();
                                      safe_glEnableVertexAttribArray(h_aPosition);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
                                      safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      safe_glEnableVertexAttribArray(h_aNormal);
                                      glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
                                      safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
                                      glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
                                      safe_glUniform1f(h_uMaterial, 1.0);
                                      glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
                                      ModelTrans.popMatrix();
                                  }
    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
}




