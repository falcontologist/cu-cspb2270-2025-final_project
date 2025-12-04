import pandas as pd
from rdflib import Graph, Literal, BNode, Namespace
import re

# namespaces
EX = Namespace("http://example.org/ns/causal/")
RDF = Namespace("http://www.w3.org/1999/02/22-rdf-syntax-ns#")
RDFS = Namespace("http://www.w3.org/2000/01/rdf-schema#")

# initialize graph
g = Graph()
g.bind("ex", EX)
g.bind("rdf", RDF)
g.bind("rdfs", RDFS)

# load CSV data from annotations file
df = pd.read_csv("annotations.csv")

# generate reified triples
for index, row in df.iterrows():
    
    # subject: a blank node
    causation_bnode = BNode() 
    
    # instance of ex:Causation
    g.add((causation_bnode, RDF.type, EX.Causation))
    
    #properties: cause, effect, connector, constructionID, recordID
         
    # cause: <_bnode> ex:cause "cause text"
    g.add((causation_bnode, EX.cause, Literal(row['cause'].strip())))
    
    # effect: <_bnode> ex:effect "effect text"
    g.add((causation_bnode, EX.effect, Literal(row['effect'].strip())))
    
    # connector: <_bnode> ex:connector "trigger text"
    g.add((causation_bnode, EX.connector, Literal(row['trigger'].strip())))
    
    # constructionID: <_bnode> ex:constructionID "C148"
    g.add((causation_bnode, EX.constructionID, Literal(row['construction_id'].strip())))
    
    # recordID: <_bnode> ex:recordID "193383"
    g.add((causation_bnode, EX.recordID, Literal(str(row['record_id']).strip())))

# serialize output
output_file = 'causal_links.ttl'
g.serialize(destination=output_file, format='turtle')

print(f"Successfully generated reified RDF triples and saved to {output_file}.")