from blastparser import HitsDataContainer
print("Filtering hits by surface accessibility...")
#SQLITE_DATABASE_DIR = "../../epitopedia.sqlite3"
#PDB_INPUT="6VXX_A"
#rasa_span=3
#rasa=0.20
#csvfile="EPI_SEQ_span_filt_hits_6VXX_A.tsv"
#outprefix="EPI_SEQ_span_filt_acc_hits"
import sys
SQLITE_DATABASE_DIR = sys.argv[1]
PDB_INPUT=sys.argv[2]
rasa_span=int(sys.argv[3])
rasa=float(sys.argv[4])
csvfile=sys.argv[5]
outprefix=sys.argv[6]


hits = HitsDataContainer()
hits.fromcsv(f"{csvfile}")
hits = hits.filterbyacc(rasa_span, rasa)
hits.tocsv(f"{outprefix}_{PDB_INPUT}.tsv", SQLITE_DATABASE_DIR)
print("Hits filtered by surface accessibility")
print(f"Number of hits remaining after surface accessibility filter {PDB_INPUT}: {len(hits)}")

