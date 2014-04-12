
#include "Models.h"
void DrawTrunk1(){

  /* circle */
  static int trunk1Index;

    	CurrentMesh = 61; //small spheres also in minimask
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();
        ModelTrans.translate(vec3(28, 5, 0)); 
          if(flag == 0){
	          trunk1Index = centers.size();
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

            /* trunk */
          	for(int k = 1; k < 3; k++){
          		CurrentMesh = 47;
			  	safe_glEnableVertexAttribArray(h_aPosition);
			  	safe_glEnableVertexAttribArray(h_aNormal); 
			 	ModelTrans.pushMatrix();
			 	
			 	if(k == 1){
			    	ModelTrans.rotate(10, vec3(1, 0, 0));
				}else if(k == 2){
					ModelTrans.translate(vec3(0, 0, 5));
					ModelTrans.rotate(-11.5, vec3(1, 0, 0));
				}

			    SetModel();
			    safe_glEnableVertexAttribArray(h_aPosition);
			    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
			    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
			    safe_glEnableVertexAttribArray(h_aNormal);
			    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
			    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
			    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
			    glUniform3f(h_uColor, 0, 0, 0);
			    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
			    ModelTrans.popMatrix();
			}
				    /* white trunk */
		          	for(int l = 1; l < 3; l++){
		          		CurrentMesh = 48;
					  	safe_glEnableVertexAttribArray(h_aPosition);
					  	safe_glEnableVertexAttribArray(h_aNormal); 
					 	ModelTrans.pushMatrix();
					 	
					 	if(l == 1){
					 		ModelTrans.translate(vec3(-0.3, 0, 0));
					    	ModelTrans.rotate(10, vec3(1, 0, 0));
						}else if(l == 2){
							ModelTrans.translate(vec3(-0.3, 0, 5));
							ModelTrans.rotate(-11.5, vec3(1, 0, 0));
						}

					    SetModel();
					    safe_glEnableVertexAttribArray(h_aPosition);
					    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
					    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
					    safe_glEnableVertexAttribArray(h_aNormal);
					    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
					    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
					    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
					    glUniform3f(h_uColor, changeColor[trunk1Index].x, changeColor[trunk1Index].y, changeColor[trunk1Index].z);
					    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
					    ModelTrans.popMatrix();
					}

							/* branch */
							for(int b = 1; b < 6; b++){
								CurrentMesh = 50;
						    	ModelTrans.pushMatrix();
							    if(b == 1){
						    	    ModelTrans.translate(vec3(0, 0.5, 3));
								    ModelTrans.rotate(70, vec3(1, 0, 0));
								}else if(b ==2){
									ModelTrans.translate(vec3(0, -1.0, 6.5));
								    ModelTrans.rotate(43, vec3(1, 0, 0));
								}else if(b ==3){
									ModelTrans.translate(vec3(0, -1.4, -2.0));
								    ModelTrans.rotate(-30, vec3(1, 0, 0));
								}else if(b ==4){
									ModelTrans.translate(vec3(0, -1.3, -2.5));
								    ModelTrans.rotate(-25, vec3(1, 0, 0));
								}else if(b ==5){
									ModelTrans.translate(vec3(0, 0, 3));
								    ModelTrans.rotate(65, vec3(1, 0, 0));
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
							    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
							    ModelTrans.popMatrix();
						    }

								    /* white branch */
									for(int q = 1; q < 6; q++){
										CurrentMesh = 51;
								    	ModelTrans.pushMatrix();
									    if(q == 1){
								    	    ModelTrans.translate(vec3(-0.3, 0.5, 3));
										    ModelTrans.rotate(70, vec3(1, 0, 0));
										}else if(q ==2){
											ModelTrans.translate(vec3(-0.3, -0.8, 6.7));
										    ModelTrans.rotate(43, vec3(1, 0, 0));
										}else if(q ==3){
											ModelTrans.translate(vec3(-0.3, -1.4, -2.0));
										    ModelTrans.rotate(-30, vec3(1, 0, 0));
										}else if(q ==4){
											ModelTrans.translate(vec3(-0.3, -1.0, -2.3));
										    ModelTrans.rotate(-27, vec3(1, 0, 0));
										}else if(q ==5){
											ModelTrans.translate(vec3(-0.3, 0.15, 2.7));
										    ModelTrans.rotate(67, vec3(1, 0, 0));
										}
									    SetModel();
									    safe_glEnableVertexAttribArray(h_aPosition);
									    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
									    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
									    safe_glEnableVertexAttribArray(h_aNormal);
									    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
									    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
									    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
									    glUniform3f(h_uColor, changeColor[trunk1Index].x, changeColor[trunk1Index].y, changeColor[trunk1Index].z);
									    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
									    ModelTrans.popMatrix();
								    }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

  }



  void DrawTrunk2(){

  /* circle */
  static int trunk2Index;

    	CurrentMesh = 61; //small spheres also in minimask
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();
        ModelTrans.rotate( 52, vec3(0, 1, 0));
        ModelTrans.translate(vec3(25, 5, 0)); 
          if(flag == 0){
	          trunk2Index = centers.size();
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

            /* trunk */
          	for(int k = 1; k < 3; k++){
          		CurrentMesh = 47;
			  	safe_glEnableVertexAttribArray(h_aPosition);
			  	safe_glEnableVertexAttribArray(h_aNormal); 
			 	ModelTrans.pushMatrix();
			 	
			 	if(k == 1){
			    	ModelTrans.rotate(10, vec3(1, 0, 0));
				}else if(k == 2){
					ModelTrans.translate(vec3(0, 0, 5));
					ModelTrans.rotate(-11.5, vec3(1, 0, 0));
				}

			    SetModel();
			    safe_glEnableVertexAttribArray(h_aPosition);
			    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
			    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
			    safe_glEnableVertexAttribArray(h_aNormal);
			    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
			    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
			    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
			    glUniform3f(h_uColor, 0, 0, 0);
			    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
			    ModelTrans.popMatrix();
			}
				    /* white trunk */
		          	for(int l = 1; l < 3; l++){
		          		CurrentMesh = 48;
					  	safe_glEnableVertexAttribArray(h_aPosition);
					  	safe_glEnableVertexAttribArray(h_aNormal); 
					 	ModelTrans.pushMatrix();
					 	
					 	if(l == 1){
					 		ModelTrans.translate(vec3(-0.3, 0, 0));
					    	ModelTrans.rotate(10, vec3(1, 0, 0));
						}else if(l == 2){
							ModelTrans.translate(vec3(-0.3, 0, 5));
							ModelTrans.rotate(-11.5, vec3(1, 0, 0));
						}

					    SetModel();
					    safe_glEnableVertexAttribArray(h_aPosition);
					    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
					    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
					    safe_glEnableVertexAttribArray(h_aNormal);
					    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
					    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
					    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
					    glUniform3f(h_uColor, changeColor[trunk2Index].x, changeColor[trunk2Index].y, changeColor[trunk2Index].z);
					    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
					    ModelTrans.popMatrix();
					}

							/* branch */
							for(int b = 1; b < 6; b++){
								CurrentMesh = 50;
						    	ModelTrans.pushMatrix();
							    if(b == 1){
						    	    ModelTrans.translate(vec3(0, 0.5, 3));
								    ModelTrans.rotate(70, vec3(1, 0, 0));
								}else if(b ==2){
									ModelTrans.translate(vec3(0, -1.0, 6.5));
								    ModelTrans.rotate(43, vec3(1, 0, 0));
								}else if(b ==3){
									ModelTrans.translate(vec3(0, -1.4, -2.0));
								    ModelTrans.rotate(-30, vec3(1, 0, 0));
								}else if(b ==4){
									ModelTrans.translate(vec3(0, -1.3, -2.5));
								    ModelTrans.rotate(-25, vec3(1, 0, 0));
								}else if(b ==5){
									ModelTrans.translate(vec3(0, 0, 3));
								    ModelTrans.rotate(65, vec3(1, 0, 0));
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
							    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
							    ModelTrans.popMatrix();
						    }

								    /* white branch */
									for(int q = 1; q < 6; q++){
										CurrentMesh = 51;
								    	ModelTrans.pushMatrix();
									    if(q == 1){
								    	    ModelTrans.translate(vec3(-0.3, 0.5, 3));
										    ModelTrans.rotate(70, vec3(1, 0, 0));
										}else if(q ==2){
											ModelTrans.translate(vec3(-0.3, -0.8, 6.7));
										    ModelTrans.rotate(43, vec3(1, 0, 0));
										}else if(q ==3){
											ModelTrans.translate(vec3(-0.3, -1.4, -2.0));
										    ModelTrans.rotate(-30, vec3(1, 0, 0));
										}else if(q ==4){
											ModelTrans.translate(vec3(-0.3, -1.0, -2.3));
										    ModelTrans.rotate(-27, vec3(1, 0, 0));
										}else if(q ==5){
											ModelTrans.translate(vec3(-0.3, 0.15, 2.7));
										    ModelTrans.rotate(67, vec3(1, 0, 0));
										}
									    SetModel();
									    safe_glEnableVertexAttribArray(h_aPosition);
									    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
									    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
									    safe_glEnableVertexAttribArray(h_aNormal);
									    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
									    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
									    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
									    glUniform3f(h_uColor, changeColor[trunk2Index].x, changeColor[trunk2Index].y, changeColor[trunk2Index].z);
									    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
									    ModelTrans.popMatrix();
								    }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

  }



void DrawTrunk3(){

  /* circle */
  static int trunk3Index;

    	CurrentMesh = 61; //small spheres also in minimask
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();
        ModelTrans.rotate( 103, vec3(0, 1, 0));
        ModelTrans.translate(vec3(25, 5, 0)); 
          if(flag == 0){
	          trunk3Index = centers.size();
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

            /* trunk */
          	for(int k = 1; k < 3; k++){
          		CurrentMesh = 47;
			  	safe_glEnableVertexAttribArray(h_aPosition);
			  	safe_glEnableVertexAttribArray(h_aNormal); 
			 	ModelTrans.pushMatrix();
			 	
			 	if(k == 1){
			    	ModelTrans.rotate(10, vec3(1, 0, 0));
				}else if(k == 2){
					ModelTrans.translate(vec3(0, 0, 5));
					ModelTrans.rotate(-11.5, vec3(1, 0, 0));
				}

			    SetModel();
			    safe_glEnableVertexAttribArray(h_aPosition);
			    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
			    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
			    safe_glEnableVertexAttribArray(h_aNormal);
			    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
			    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
			    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
			    glUniform3f(h_uColor, 0, 0, 0);
			    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
			    ModelTrans.popMatrix();
			}
				    /* white trunk */
		          	for(int l = 1; l < 3; l++){
		          		CurrentMesh = 48;
					  	safe_glEnableVertexAttribArray(h_aPosition);
					  	safe_glEnableVertexAttribArray(h_aNormal); 
					 	ModelTrans.pushMatrix();
					 	
					 	if(l == 1){
					 		ModelTrans.translate(vec3(-0.3, 0, 0));
					    	ModelTrans.rotate(10, vec3(1, 0, 0));
						}else if(l == 2){
							ModelTrans.translate(vec3(-0.3, 0, 5));
							ModelTrans.rotate(-11.5, vec3(1, 0, 0));
						}

					    SetModel();
					    safe_glEnableVertexAttribArray(h_aPosition);
					    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
					    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
					    safe_glEnableVertexAttribArray(h_aNormal);
					    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
					    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
					    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
					    glUniform3f(h_uColor, changeColor[trunk3Index].x, changeColor[trunk3Index].y, changeColor[trunk3Index].z);
					    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
					    ModelTrans.popMatrix();
					}

							/* branch */
							for(int b = 1; b < 6; b++){
								CurrentMesh = 50;
						    	ModelTrans.pushMatrix();
							    if(b == 1){
						    	    ModelTrans.translate(vec3(0, 0.5, 3));
								    ModelTrans.rotate(70, vec3(1, 0, 0));
								}else if(b ==2){
									ModelTrans.translate(vec3(0, -1.0, 6.5));
								    ModelTrans.rotate(43, vec3(1, 0, 0));
								}else if(b ==3){
									ModelTrans.translate(vec3(0, -1.4, -2.0));
								    ModelTrans.rotate(-30, vec3(1, 0, 0));
								}else if(b ==4){
									ModelTrans.translate(vec3(0, -1.3, -2.5));
								    ModelTrans.rotate(-25, vec3(1, 0, 0));
								}else if(b ==5){
									ModelTrans.translate(vec3(0, 0, 3));
								    ModelTrans.rotate(65, vec3(1, 0, 0));
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
							    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
							    ModelTrans.popMatrix();
						    }

								    /* white branch */
									for(int q = 1; q < 6; q++){
										CurrentMesh = 51;
								    	ModelTrans.pushMatrix();
									    if(q == 1){
								    	    ModelTrans.translate(vec3(-0.3, 0.5, 3));
										    ModelTrans.rotate(70, vec3(1, 0, 0));
										}else if(q ==2){
											ModelTrans.translate(vec3(-0.3, -0.8, 6.7));
										    ModelTrans.rotate(43, vec3(1, 0, 0));
										}else if(q ==3){
											ModelTrans.translate(vec3(-0.3, -1.4, -2.0));
										    ModelTrans.rotate(-30, vec3(1, 0, 0));
										}else if(q ==4){
											ModelTrans.translate(vec3(-0.3, -1.0, -2.3));
										    ModelTrans.rotate(-27, vec3(1, 0, 0));
										}else if(q ==5){
											ModelTrans.translate(vec3(-0.3, 0.15, 2.7));
										    ModelTrans.rotate(67, vec3(1, 0, 0));
										}
									    SetModel();
									    safe_glEnableVertexAttribArray(h_aPosition);
									    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
									    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
									    safe_glEnableVertexAttribArray(h_aNormal);
									    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
									    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
									    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
									    glUniform3f(h_uColor, changeColor[trunk3Index].x, changeColor[trunk3Index].y, changeColor[trunk3Index].z);
									    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
									    ModelTrans.popMatrix();
								    }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

  }



  void DrawTrunk4(){

  /* circle */
  static int trunk4Index;

    	CurrentMesh = 61; //small spheres also in minimask
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();
        ModelTrans.rotate( 151, vec3(0, 1, 0));
        ModelTrans.translate(vec3(25, 5, 0)); 
          if(flag == 0){
	          trunk4Index = centers.size();
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

            /* trunk */
          	for(int k = 1; k < 3; k++){
          		CurrentMesh = 47;
			  	safe_glEnableVertexAttribArray(h_aPosition);
			  	safe_glEnableVertexAttribArray(h_aNormal); 
			 	ModelTrans.pushMatrix();
			 	
			 	if(k == 1){
			    	ModelTrans.rotate(10, vec3(1, 0, 0));
				}else if(k == 2){
					ModelTrans.translate(vec3(0, 0, 5));
					ModelTrans.rotate(-11.5, vec3(1, 0, 0));
				}

			    SetModel();
			    safe_glEnableVertexAttribArray(h_aPosition);
			    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
			    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
			    safe_glEnableVertexAttribArray(h_aNormal);
			    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
			    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
			    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
			    glUniform3f(h_uColor, 0, 0, 0);
			    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
			    ModelTrans.popMatrix();
			}
				    /* white trunk */
		          	for(int l = 1; l < 3; l++){
		          		CurrentMesh = 48;
					  	safe_glEnableVertexAttribArray(h_aPosition);
					  	safe_glEnableVertexAttribArray(h_aNormal); 
					 	ModelTrans.pushMatrix();
					 	
					 	if(l == 1){
					 		ModelTrans.translate(vec3(-0.3, 0, 0));
					    	ModelTrans.rotate(10, vec3(1, 0, 0));
						}else if(l == 2){
							ModelTrans.translate(vec3(-0.3, 0, 5));
							ModelTrans.rotate(-11.5, vec3(1, 0, 0));
						}

					    SetModel();
					    safe_glEnableVertexAttribArray(h_aPosition);
					    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
					    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
					    safe_glEnableVertexAttribArray(h_aNormal);
					    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
					    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
					    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
					    glUniform3f(h_uColor, changeColor[trunk4Index].x, changeColor[trunk4Index].y, changeColor[trunk4Index].z);
					    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
					    ModelTrans.popMatrix();
					}

							/* branch */
							for(int b = 1; b < 6; b++){
								CurrentMesh = 50;
						    	ModelTrans.pushMatrix();
							    if(b == 1){
						    	    ModelTrans.translate(vec3(0, 0.5, 3));
								    ModelTrans.rotate(70, vec3(1, 0, 0));
								}else if(b ==2){
									ModelTrans.translate(vec3(0, -1.0, 6.5));
								    ModelTrans.rotate(43, vec3(1, 0, 0));
								}else if(b ==3){
									ModelTrans.translate(vec3(0, -1.4, -2.0));
								    ModelTrans.rotate(-30, vec3(1, 0, 0));
								}else if(b ==4){
									ModelTrans.translate(vec3(0, -1.3, -2.5));
								    ModelTrans.rotate(-25, vec3(1, 0, 0));
								}else if(b ==5){
									ModelTrans.translate(vec3(0, 0, 3));
								    ModelTrans.rotate(65, vec3(1, 0, 0));
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
							    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
							    ModelTrans.popMatrix();
						    }

								    /* white branch */
									for(int q = 1; q < 6; q++){
										CurrentMesh = 51;
								    	ModelTrans.pushMatrix();
									    if(q == 1){
								    	    ModelTrans.translate(vec3(-0.3, 0.5, 3));
										    ModelTrans.rotate(70, vec3(1, 0, 0));
										}else if(q ==2){
											ModelTrans.translate(vec3(-0.3, -0.8, 6.7));
										    ModelTrans.rotate(43, vec3(1, 0, 0));
										}else if(q ==3){
											ModelTrans.translate(vec3(-0.3, -1.4, -2.0));
										    ModelTrans.rotate(-30, vec3(1, 0, 0));
										}else if(q ==4){
											ModelTrans.translate(vec3(-0.3, -1.0, -2.3));
										    ModelTrans.rotate(-27, vec3(1, 0, 0));
										}else if(q ==5){
											ModelTrans.translate(vec3(-0.3, 0.15, 2.7));
										    ModelTrans.rotate(67, vec3(1, 0, 0));
										}
									    SetModel();
									    safe_glEnableVertexAttribArray(h_aPosition);
									    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
									    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
									    safe_glEnableVertexAttribArray(h_aNormal);
									    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
									    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
									    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
									    glUniform3f(h_uColor, changeColor[trunk4Index].x, changeColor[trunk4Index].y, changeColor[trunk4Index].z);
									    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
									    ModelTrans.popMatrix();
								    }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

  }


void DrawTrunk5(){

  /* circle */
  static int trunk5Index;

    	CurrentMesh = 61; //small spheres also in minimask
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();
        ModelTrans.rotate( 202, vec3(0, 1, 0));
        ModelTrans.translate(vec3(25, 5, 0)); 
          if(flag == 0){
	          trunk5Index = centers.size();
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

            /* trunk */
          	for(int k = 1; k < 3; k++){
          		CurrentMesh = 47;
			  	safe_glEnableVertexAttribArray(h_aPosition);
			  	safe_glEnableVertexAttribArray(h_aNormal); 
			 	ModelTrans.pushMatrix();
			 	
			 	if(k == 1){
			    	ModelTrans.rotate(10, vec3(1, 0, 0));
				}else if(k == 2){
					ModelTrans.translate(vec3(0, 0, 5));
					ModelTrans.rotate(-11.5, vec3(1, 0, 0));
				}

			    SetModel();
			    safe_glEnableVertexAttribArray(h_aPosition);
			    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
			    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
			    safe_glEnableVertexAttribArray(h_aNormal);
			    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
			    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
			    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
			    glUniform3f(h_uColor, 0, 0, 0);
			    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
			    ModelTrans.popMatrix();
			}
				    /* white trunk */
		          	for(int l = 1; l < 3; l++){
		          		CurrentMesh = 48;
					  	safe_glEnableVertexAttribArray(h_aPosition);
					  	safe_glEnableVertexAttribArray(h_aNormal); 
					 	ModelTrans.pushMatrix();
					 	
					 	if(l == 1){
					 		ModelTrans.translate(vec3(-0.3, 0, 0));
					    	ModelTrans.rotate(10, vec3(1, 0, 0));
						}else if(l == 2){
							ModelTrans.translate(vec3(-0.3, 0, 5));
							ModelTrans.rotate(-11.5, vec3(1, 0, 0));
						}

					    SetModel();
					    safe_glEnableVertexAttribArray(h_aPosition);
					    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
					    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
					    safe_glEnableVertexAttribArray(h_aNormal);
					    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
					    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
					    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
					    glUniform3f(h_uColor, changeColor[trunk5Index].x, changeColor[trunk5Index].y, changeColor[trunk5Index].z);
					    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
					    ModelTrans.popMatrix();
					}

							/* branch */
							for(int b = 1; b < 6; b++){
								CurrentMesh = 50;
						    	ModelTrans.pushMatrix();
							    if(b == 1){
						    	    ModelTrans.translate(vec3(0, 0.5, 3));
								    ModelTrans.rotate(70, vec3(1, 0, 0));
								}else if(b ==2){
									ModelTrans.translate(vec3(0, -1.0, 6.5));
								    ModelTrans.rotate(43, vec3(1, 0, 0));
								}else if(b ==3){
									ModelTrans.translate(vec3(0, -1.4, -2.0));
								    ModelTrans.rotate(-30, vec3(1, 0, 0));
								}else if(b ==4){
									ModelTrans.translate(vec3(0, -1.3, -2.5));
								    ModelTrans.rotate(-25, vec3(1, 0, 0));
								}else if(b ==5){
									ModelTrans.translate(vec3(0, 0, 3));
								    ModelTrans.rotate(65, vec3(1, 0, 0));
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
							    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
							    ModelTrans.popMatrix();
						    }

								    /* white branch */
									for(int q = 1; q < 6; q++){
										CurrentMesh = 51;
								    	ModelTrans.pushMatrix();
									    if(q == 1){
								    	    ModelTrans.translate(vec3(-0.3, 0.5, 3));
										    ModelTrans.rotate(70, vec3(1, 0, 0));
										}else if(q ==2){
											ModelTrans.translate(vec3(-0.3, -0.8, 6.7));
										    ModelTrans.rotate(43, vec3(1, 0, 0));
										}else if(q ==3){
											ModelTrans.translate(vec3(-0.3, -1.4, -2.0));
										    ModelTrans.rotate(-30, vec3(1, 0, 0));
										}else if(q ==4){
											ModelTrans.translate(vec3(-0.3, -1.0, -2.3));
										    ModelTrans.rotate(-27, vec3(1, 0, 0));
										}else if(q ==5){
											ModelTrans.translate(vec3(-0.3, 0.15, 2.7));
										    ModelTrans.rotate(67, vec3(1, 0, 0));
										}
									    SetModel();
									    safe_glEnableVertexAttribArray(h_aPosition);
									    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
									    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
									    safe_glEnableVertexAttribArray(h_aNormal);
									    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
									    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
									    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
									    glUniform3f(h_uColor, changeColor[trunk5Index].x, changeColor[trunk5Index].y, changeColor[trunk5Index].z);
									    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
									    ModelTrans.popMatrix();
								    }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

  }



void DrawTrunk6(){

  /* circle */
  static int trunk6Index;

    	CurrentMesh = 61; //small spheres also in minimask
        safe_glEnableVertexAttribArray(h_aPosition);
        safe_glEnableVertexAttribArray(h_aNormal); 
        ModelTrans.pushMatrix();
        ModelTrans.rotate( -50, vec3(0, 1, 0));
        ModelTrans.translate(vec3(28, 5, 0)); 
          if(flag == 0){
	          trunk6Index = centers.size();
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

            /* trunk */
          	for(int k = 1; k < 3; k++){
          		CurrentMesh = 47;
			  	safe_glEnableVertexAttribArray(h_aPosition);
			  	safe_glEnableVertexAttribArray(h_aNormal); 
			 	ModelTrans.pushMatrix();
			 	
			 	if(k == 1){
			    	ModelTrans.rotate(10, vec3(1, 0, 0));
				}else if(k == 2){
					ModelTrans.translate(vec3(0, 0, 5));
					ModelTrans.rotate(-11.5, vec3(1, 0, 0));
				}

			    SetModel();
			    safe_glEnableVertexAttribArray(h_aPosition);
			    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
			    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
			    safe_glEnableVertexAttribArray(h_aNormal);
			    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
			    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
			    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
			    glUniform3f(h_uColor, 0, 0, 0);
			    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
			    ModelTrans.popMatrix();
			}
				    /* white trunk */
		          	for(int l = 1; l < 3; l++){
		          		CurrentMesh = 48;
					  	safe_glEnableVertexAttribArray(h_aPosition);
					  	safe_glEnableVertexAttribArray(h_aNormal); 
					 	ModelTrans.pushMatrix();
					 	
					 	if(l == 1){
					 		ModelTrans.translate(vec3(-0.3, 0, 0));
					    	ModelTrans.rotate(10, vec3(1, 0, 0));
						}else if(l == 2){
							ModelTrans.translate(vec3(-0.3, 0, 5));
							ModelTrans.rotate(-11.5, vec3(1, 0, 0));
						}

					    SetModel();
					    safe_glEnableVertexAttribArray(h_aPosition);
					    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
					    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
					    safe_glEnableVertexAttribArray(h_aNormal);
					    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
					    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
					    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
					    glUniform3f(h_uColor, changeColor[trunk6Index].x, changeColor[trunk6Index].y, changeColor[trunk6Index].z);
					    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
					    ModelTrans.popMatrix();
					}

							/* branch */
							for(int b = 1; b < 6; b++){
								CurrentMesh = 50;
						    	ModelTrans.pushMatrix();
							    if(b == 1){
						    	    ModelTrans.translate(vec3(0, 0.5, 3));
								    ModelTrans.rotate(70, vec3(1, 0, 0));
								}else if(b ==2){
									ModelTrans.translate(vec3(0, -1.0, 6.5));
								    ModelTrans.rotate(43, vec3(1, 0, 0));
								}else if(b ==3){
									ModelTrans.translate(vec3(0, -1.4, -2.0));
								    ModelTrans.rotate(-30, vec3(1, 0, 0));
								}else if(b ==4){
									ModelTrans.translate(vec3(0, -1.3, -2.5));
								    ModelTrans.rotate(-25, vec3(1, 0, 0));
								}else if(b ==5){
									ModelTrans.translate(vec3(0, 0, 3));
								    ModelTrans.rotate(65, vec3(1, 0, 0));
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
							    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
							    ModelTrans.popMatrix();
						    }

								    /* white branch */
									for(int q = 1; q < 6; q++){
										CurrentMesh = 51;
								    	ModelTrans.pushMatrix();
									    if(q == 1){
								    	    ModelTrans.translate(vec3(-0.3, 0.5, 3));
										    ModelTrans.rotate(70, vec3(1, 0, 0));
										}else if(q ==2){
											ModelTrans.translate(vec3(-0.3, -0.8, 6.7));
										    ModelTrans.rotate(43, vec3(1, 0, 0));
										}else if(q ==3){
											ModelTrans.translate(vec3(-0.3, -1.4, -2.0));
										    ModelTrans.rotate(-30, vec3(1, 0, 0));
										}else if(q ==4){
											ModelTrans.translate(vec3(-0.3, -1.0, -2.3));
										    ModelTrans.rotate(-27, vec3(1, 0, 0));
										}else if(q ==5){
											ModelTrans.translate(vec3(-0.3, 0.15, 2.7));
										    ModelTrans.rotate(67, vec3(1, 0, 0));
										}
									    SetModel();
									    safe_glEnableVertexAttribArray(h_aPosition);
									    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->PositionHandle);
									    safe_glVertexAttribPointer(h_aPosition, 3, GL_FLOAT, GL_FALSE, 0, 0);
									    safe_glEnableVertexAttribArray(h_aNormal);
									    glBindBuffer(GL_ARRAY_BUFFER, Meshes[CurrentMesh]->NormalHandle);
									    safe_glVertexAttribPointer(h_aNormal, 3, GL_FLOAT, GL_FALSE, 0, 0);
									    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Meshes[CurrentMesh]->IndexHandle);
									    glUniform3f(h_uColor, changeColor[trunk6Index].x, changeColor[trunk6Index].y, changeColor[trunk6Index].z);
									    glDrawElements(GL_TRIANGLES, Meshes[CurrentMesh]->IndexBufferLength, GL_UNSIGNED_SHORT, 0);
									    ModelTrans.popMatrix();
								    }

    ModelTrans.popMatrix();
    safe_glDisableVertexAttribArray(h_aPosition);  
    safe_glDisableVertexAttribArray(h_aNormal);

  }