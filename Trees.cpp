


#include "Models.h"
void DrawTree1(){

  static int tree1Index;
  		//small sphere arbitrary center
    	CurrentMesh = 61; 
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          	ModelTrans.translate(vec3(28, 11, 0)); 
		  	    if(flag == 0){
		          tree1Index = centers.size();
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

          	    /* big black circles for foliage */
          		for(int t = 1; t<4; t++){
          		  	CurrentMesh = 45;
				    safe_glEnableVertexAttribArray(h_aPosition);
				    safe_glEnableVertexAttribArray(h_aNormal); 
					ModelTrans.pushMatrix();
					
					
					if(t == 2){
						ModelTrans.translate(vec3(0, -1, 6));
					}else if (t ==3){
						ModelTrans.translate(vec3(0, -1, -4));
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
						//white spheres inside trees 
						for(int w = 1; w < 4; w++){ 
				              CurrentMesh = 46;
				              safe_glEnableVertexAttribArray(h_aPosition);
				              safe_glEnableVertexAttribArray(h_aNormal); 
				              ModelTrans.pushMatrix();
				              if(w == 1){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              }else if(w == 2){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              	ModelTrans.translate(vec3(0, -1, 6));
				              }else if( w == 3){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              	ModelTrans.translate(vec3(0, -1, -4));
				              }
	
				                SetModel();

				                safe_glEnableVertexAttribArray(h_aPosition);
				                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
				                safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
				                safe_glEnableVertexAttribArray(h_aNormal);
				                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
				                safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
				                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
				                glUniform3f(h_uColor, changeColor[tree1Index].x, changeColor[tree1Index].y, changeColor[tree1Index].z);
				                safe_glUniform1f(h_uMaterial, 1.0);
				                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
				                ModelTrans.popMatrix();
			            }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);
  }



void DrawTree2(){

  static int tree2Index;

  		//small sphere arbitrary center
    	CurrentMesh = 61; 
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          	ModelTrans.rotate( 50, vec3(0, 1, 0));
          	ModelTrans.translate(vec3(25, 11, 0)); 
		  	if(flag == 0){
		        tree2Index = centers.size();
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

          	    /* big black circles for foliage */
          		for(int t = 1; t<4; t++){
          		  	CurrentMesh = 45;
				    safe_glEnableVertexAttribArray(h_aPosition);
				    safe_glEnableVertexAttribArray(h_aNormal); 
					ModelTrans.pushMatrix();
					if(t == 2){
						ModelTrans.translate(vec3(0, -1, 6));
					}else if (t ==3){
						ModelTrans.translate(vec3(0, -1, -4));
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
						//white spheres inside trees 
						for(int w = 1; w < 4; w++){ 
				              CurrentMesh = 46;
				              safe_glEnableVertexAttribArray(h_aPosition);
				              safe_glEnableVertexAttribArray(h_aNormal); 
				              ModelTrans.pushMatrix();
				              if(w == 1){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              }else if(w == 2){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              	ModelTrans.translate(vec3(0, -1, 6));
				              }else if( w == 3){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              	ModelTrans.translate(vec3(0, -1, -4));
				              }
				                SetModel();

				                safe_glEnableVertexAttribArray(h_aPosition);
				                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
				                safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
				                safe_glEnableVertexAttribArray(h_aNormal);
				                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
				                safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
				                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
				                glUniform3f(h_uColor, changeColor[tree2Index].x, changeColor[tree2Index].y, changeColor[tree2Index].z);
				                safe_glUniform1f(h_uMaterial, 1.0);
				                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
				                ModelTrans.popMatrix();
			            }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);	
  }



  void DrawTree3(){

  	static int tree3Index;

  		//small sphere arbitrary center
    	CurrentMesh = 61; 
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          	ModelTrans.rotate( 100, vec3(0, 1, 0));
          	ModelTrans.translate(vec3(25, 11, 0)); 
		  	if(flag == 0){
		        tree3Index = centers.size();
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

          	    /* big black circles for foliage */
          		for(int t = 1; t<4; t++){
          		  	CurrentMesh = 45;
				    safe_glEnableVertexAttribArray(h_aPosition);
				    safe_glEnableVertexAttribArray(h_aNormal); 
					ModelTrans.pushMatrix();
					if(t == 2){
						ModelTrans.translate(vec3(0, -1, 6));
					}else if (t ==3){
						ModelTrans.translate(vec3(0, -1, -4));
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
						//white spheres inside trees 
						for(int w = 1; w < 4; w++){ 
				              CurrentMesh = 46;
				              safe_glEnableVertexAttribArray(h_aPosition);
				              safe_glEnableVertexAttribArray(h_aNormal); 
				              ModelTrans.pushMatrix();
				              if(w == 1){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              }else if(w == 2){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              	ModelTrans.translate(vec3(0, -1, 6));
				              }else if( w == 3){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              	ModelTrans.translate(vec3(0, -1, -4));
				              }
				                SetModel();

				                safe_glEnableVertexAttribArray(h_aPosition);
				                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
				                safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
				                safe_glEnableVertexAttribArray(h_aNormal);
				                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
				                safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
				                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
				                glUniform3f(h_uColor, changeColor[tree3Index].x, changeColor[tree3Index].y, changeColor[tree3Index].z);
				                safe_glUniform1f(h_uMaterial, 1.0);
				                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
				                ModelTrans.popMatrix();
			            }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);	
  }



  void DrawTree4(){

  static int tree4Index;

  		//small sphere arbitrary center
    	CurrentMesh = 61; 
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          	ModelTrans.rotate( 150, vec3(0, 1, 0));
          	ModelTrans.translate(vec3(25, 11, 0)); 
		  	if(flag == 0){
		        tree4Index = centers.size();
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

          	    /* big black circles for foliage */
          		for(int t = 1; t<4; t++){
          		  	CurrentMesh = 45;
				    safe_glEnableVertexAttribArray(h_aPosition);
				    safe_glEnableVertexAttribArray(h_aNormal); 
					ModelTrans.pushMatrix();
					if(t == 2){
						ModelTrans.translate(vec3(0, -1, 6));
					}else if (t ==3){
						ModelTrans.translate(vec3(0, -1, -4));
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
						//white spheres inside trees 
						for(int w = 1; w < 4; w++){ 
				              CurrentMesh = 46;
				              safe_glEnableVertexAttribArray(h_aPosition);
				              safe_glEnableVertexAttribArray(h_aNormal); 
				              ModelTrans.pushMatrix();
				              if(w == 1){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              }else if(w == 2){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              	ModelTrans.translate(vec3(0, -1, 6));
				              }else if( w == 3){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              	ModelTrans.translate(vec3(0, -1, -4));
				              }
				                SetModel();

				                safe_glEnableVertexAttribArray(h_aPosition);
				                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
				                safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
				                safe_glEnableVertexAttribArray(h_aNormal);
				                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
				                safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
				                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
				                glUniform3f(h_uColor, changeColor[tree4Index].x, changeColor[tree4Index].y, changeColor[tree4Index].z);
				                safe_glUniform1f(h_uMaterial, 1.0);
				                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
				                ModelTrans.popMatrix();
			            }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);	
  }



  void DrawTree5(){

  static int tree5Index;

  		//small sphere arbitrary center
    	CurrentMesh = 61; 
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          	ModelTrans.rotate( 200, vec3(0, 1, 0));
          	ModelTrans.translate(vec3(25, 11, 0)); 
		  	if(flag == 0){
		        tree5Index = centers.size();
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

          	    /* big black circles for foliage */
          		for(int t = 1; t<4; t++){
          		  	CurrentMesh = 45;
				    safe_glEnableVertexAttribArray(h_aPosition);
				    safe_glEnableVertexAttribArray(h_aNormal); 
					ModelTrans.pushMatrix();
					if(t == 2){
						ModelTrans.translate(vec3(0, -1, 6));
					}else if (t ==3){
						ModelTrans.translate(vec3(0, -1, -4));
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
						//white spheres inside trees 
						for(int w = 1; w < 4; w++){ 
				              CurrentMesh = 46;
				              safe_glEnableVertexAttribArray(h_aPosition);
				              safe_glEnableVertexAttribArray(h_aNormal); 
				              ModelTrans.pushMatrix();
				              if(w == 1){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              }else if(w == 2){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              	ModelTrans.translate(vec3(0, -1, 6));
				              }else if( w == 3){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              	ModelTrans.translate(vec3(0, -1, -4));
				              }
				                SetModel();

				                safe_glEnableVertexAttribArray(h_aPosition);
				                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
				                safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
				                safe_glEnableVertexAttribArray(h_aNormal);
				                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
				                safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
				                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
				                glUniform3f(h_uColor, changeColor[tree5Index].x, changeColor[tree5Index].y, changeColor[tree5Index].z);
				                safe_glUniform1f(h_uMaterial, 1.0);
				                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
				                ModelTrans.popMatrix();
			            }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);	
  }



void DrawTree6(){

  static int tree6Index;

  		//small sphere arbitrary center
    	CurrentMesh = 61; 
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
          ModelTrans.pushMatrix();
          	ModelTrans.rotate( -50, vec3(0, 1, 0));
          	ModelTrans.translate(vec3(28, 11, 0)); 
		  	if(flag == 0){
		        tree6Index = centers.size();
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

          	    /* big black circles for foliage */
          		for(int t = 1; t<4; t++){
          		  	CurrentMesh = 45;
				    safe_glEnableVertexAttribArray(h_aPosition);
				    safe_glEnableVertexAttribArray(h_aNormal); 
					ModelTrans.pushMatrix();
					if(t == 2){
						ModelTrans.translate(vec3(0, -1, 6));
					}else if (t ==3){
						ModelTrans.translate(vec3(0, -1, -4));
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
						//white spheres inside trees 
						for(int w = 1; w < 4; w++){ 
				              CurrentMesh = 46;
				              safe_glEnableVertexAttribArray(h_aPosition);
				              safe_glEnableVertexAttribArray(h_aNormal); 
				              ModelTrans.pushMatrix();
				              if(w == 1){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              }else if(w == 2){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              	ModelTrans.translate(vec3(0, -1, 6));
				              }else if( w == 3){
				              	ModelTrans.translate(vec3(-0.5, -0.25, 0));
				              	ModelTrans.translate(vec3(0, -1, -4));
				              }
				                SetModel();

				                safe_glEnableVertexAttribArray(h_aPosition);
				                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
				                safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
				                safe_glEnableVertexAttribArray(h_aNormal);
				                glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
				                safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
				                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
				                glUniform3f(h_uColor, changeColor[tree6Index].x, changeColor[tree6Index].y, changeColor[tree6Index].z);
				                safe_glUniform1f(h_uMaterial, 1.0);
				                glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
				                ModelTrans.popMatrix();
			            }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);	
  }





